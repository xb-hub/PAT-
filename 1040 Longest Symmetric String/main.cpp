#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n = s.length(), max_ = 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if(i < n - 1 && s[i] == s[i + 1])
        {
            dp[i + 1][i] = 2;
            max_ = 2;
        }
    }
    for(int i = 2; i < n; i++)
    {
        for(int j = i - 2; j >= 0; j--)
        {
            if(s[j] == s[i] && dp[i - 1][j + 1] != 0)
            {
                dp[i][j] = dp[i - 1][j + 1] + 2;
                max_ = max(max_, dp[i][j]);
            }
        }
    }
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << max_ << endl;
}