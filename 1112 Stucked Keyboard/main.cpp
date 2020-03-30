#include <iostream>
using namespace std;

int main()
{
    int k, count = 1, tmp = 1;
    cin >> k;
    string s;
    cin >> s;
    int flag[100] = {0};
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i - 1])
        {
            count++;
            continue;
        }
        else
        {
            tmp = count;
            count = 1;
        }
        if(tmp % k == 0)
        {
            if(flag[s[i - 1]] != 1)
            {
                flag[s[i - 1]] = 2;
            }
        }
        else
        {
            flag[s[i - 1]] = 1;
        }
    }
}