#include <iostream>
#include <string>

int ConvertAndCompare(string input)
{
    int initial = 0;
    sscanf(input.c_str(), "%d", &initial);
    return (initial % 3) == 0 ? 1 : 0;
}

int solution(string &S)
{
    string copy = S;
    int count = ConvertAndCompare(copy);
    for(int i = 0 ;i < S.size(); ++i)
    {
        for(int j = 0 ;j <= 9; ++j)
        {
            string replace = to_string(j);
            copy.replace(i, 1, replace);
            if(copy != S)
            {
                count += ConvertAndCompare(copy);
            }
        }
        copy = S;
    }
    cout << count << endl;
    return count;
}

main ()
{
  string s("23");
  solution(s);
}