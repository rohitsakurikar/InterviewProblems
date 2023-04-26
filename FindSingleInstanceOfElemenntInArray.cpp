/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// #include <iostream>
// #include <vector>

// using namespace std;

// std::vector<int> a = {32,3,6,3,32,6,9,9,5};

// uint FindOneOccurence(std::vector<int>& array)
// {
// 	uint singleElement;
// 	bool found = false;

// 	for(auto pivotItr = array.begin();pivotItr != array.end(); ++pivotItr)
// 	{
// 		found = false;
// 		for(auto itr = pivotItr + 1; itr != array.end(); ++itr)
// 		{
// 			if(*(pivotItr) == *(itr))
// 			{
// 				found = true;
// 				break;
// 			}
// 		}
// 		if(!found)
// 		{
// 			singleElement = *(pivotItr);
// 		}
// 	}
// 	return singleElement;
// }

// int main()
// {
//     cout << FindOneOccurence(a);
    
//     uint result = 0;
//     for(int i = 0; i < a.size(); ++i)
//     {
//         cout << result ^ a[i];
//     }

//     return 0;
// }

#include <iostream>   
using namespace std;

int findSingle(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = result ^ arr[i]; // XOR operation
    }
    return result;
}

int main() {
    int arr[] = {32,3,6,3,32,6,9,9,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int element = findSingle(arr, n);
    cout << "The element that appears only once is: " << element << endl;
    return 0;
}
