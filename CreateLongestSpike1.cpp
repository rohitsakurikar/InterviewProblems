#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& arr)
{
    for(auto it = arr.begin(); it != arr.end();++it)
    {
        cout << *it << ", ";
    }
    cout << endl;
}

void findDuplicateInLower(vector<int>& low, vector<int>& high, bool sortAssending)
{
    vector<int> duplicate;
    for (int i = 1; i < low.size(); i++) {
        if (low[i - 1] == low[i]) {
 
            if (duplicate.empty())
                duplicate.push_back(low[i]);
            else if (low[i] != duplicate.back())
                duplicate.push_back(low[i]);
        }
    }
 
    for (int i = 0; i < duplicate.size(); i++)
    {
        if(!(std::find(high.begin(), high.end(), duplicate[i]) != high.end()))
        {
            high.push_back(duplicate[i]);
        }
        low.erase(std::find(low.begin(), low.end(), duplicate[i]));
    }
    if(sortAssending)
        sort(low.begin(), low.end());
    else
        sort(low.begin(), low.end(), greater<int>());
}

int solution(vector<int>& arr)
{
    int vectorMid = (arr.size()/2);
    int maxIndex = std::max_element(arr.begin(),arr.end()) - arr.begin();
    int maxElement = *std::max_element(arr.begin(), arr.end());

    swap(arr[maxIndex], arr[vectorMid]);

    vector<int> lowerArr(arr.begin(), arr.begin()+(vectorMid));
    vector<int> higherArr(arr.begin()+(vectorMid+1), arr.end());

    findDuplicateInLower(lowerArr, higherArr, true);
    findDuplicateInLower(higherArr, lowerArr, false);

    vector<int> spikeVector;
    for(auto it : lowerArr)
    {
        spikeVector.push_back(it);
    }
    if(!(std::find(higherArr.begin(), higherArr.end(), maxElement) != higherArr.end()) &&
       !(std::find(lowerArr.begin(), lowerArr.end(), maxElement) != lowerArr.end())) 
    {
        spikeVector.push_back(maxElement);    
    }
    for(auto it : higherArr)
    {
        spikeVector.push_back(it);
    }
    printVector(spikeVector);
    return spikeVector.size();
}

int
main ()
{
//   vector<int> arr = {1, 2};
//   vector<int> arr = {2, 5, 3, 2, 4, 1};
//   vector<int> arr = {4, 5, 7, 6, 3, 2};
  vector<int> arr = {2, 3, 3, 2, 2, 2, 1};
  int spikeSize = solution(arr);
  cout << "Spike size: " << spikeSize << endl;
  return 0;
}