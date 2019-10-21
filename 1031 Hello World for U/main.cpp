#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int bottom;
    for(bottom = 3; bottom < s.size(); bottom++)
    {
        if((s.size() - bottom) % 2 == 0 && ((s.size() - bottom) / 2 + 1) <= bottom)
        {
            break;
        }
    }
    int lr = (s.size() - bottom) / 2;
    // cout << bottom << " " << lr << endl;
    char ans[30][30];
    memset(ans, ' ', sizeof(ans));
    int temp = 0, b_temp = lr - 1;
    for(int i = 0; i < s.size(); i++)
    {
        if(i < lr)  ans[i][0] = s[i];
        else if(i < lr + bottom)   ans[lr][temp++] = s[i];
        else    ans[b_temp--][bottom - 1] = s[i];
    }
    for(int i = 0; i <= lr; i++)
    {
        for(int j = 0; j < bottom; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
}