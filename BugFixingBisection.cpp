#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& A, int X) {
    int N = A.size();
    if (N == 0) {
        return -1;
    }
    int l = 0;
    int r = N - 1;
    while (l < r) {
        int m = ((l + r) / 2) + 1;
        if (A[m] > X) {
            r = m - 1;
        }
        else {
            l = m;
        }
    }
    if (A[l] == X) {
        return l;
    }
    return -1;
}

int main()
{
    vector<int> intV{-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10};
    cout << solution(intV, 10) << endl;
}