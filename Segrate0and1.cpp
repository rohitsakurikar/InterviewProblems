/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void Swap(int& x, int& y)
{
    x = x ^ y; // x now becomes 15 (1111)
    y = x ^ y; // y becomes 10 (1010)
    x = x ^ y; // x becomes 5 (0101)
}

void Segrate0And1InArray(std::vector<int>& array)
{
    auto itrEnd = array.end() -1;
	for(auto itrBegin = array.begin(); itrBegin < itrEnd;)
	{
	    cout << "Begin Itr: " << *itrBegin << " End Itr: " << *itrEnd << endl;
		if(*(itrBegin) > *(itrEnd))
		{
			Swap(*(itrBegin), *(itrEnd));
		}
		if(*(itrBegin) == 0)
		{
			itrBegin++;
		}
		if(*(itrEnd) == 1)
		{
			itrEnd--;
		}
	}
}

int main()
{
    std::vector<int> arr{0, 1, 0, 1, 0, 0, 1, 1, 1, 0,0,0,0,1,1};
    Segrate0And1InArray(arr);
    
    for(auto itr = arr.begin(); itr != arr.end(); ++itr)
	{
	    cout << *(itr) <<" ";
	}

    return 0;
}
