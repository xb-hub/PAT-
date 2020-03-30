#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n, m, l;
    cin >> n >> m;
    vector<int> index_(201), color;
    int color_;
    for(int i = 1; i <= m; i++)
    {
        cin >> color_;
        index_[color_] = i;
    }
    cin >> l;
    for(int i = 0; i < l; i++)
    {
        cin >> color_;
        if(index_[color_] >= 1)
        {
            color.push_back(index_[color_]);
        }
    }
    vector<int> dp(color.size());
    int max_len = 0;
    for(int i = 0; i < color.size(); i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(color[j] <= color[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }
    cout << max_len << endl;
}