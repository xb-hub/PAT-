#include <iostream>
#include <vector>
using namespace std;

/**
 * 动态规划
 * 内存超限
int main()
{
    int n, m, min_ = 100001;
    cin >> n >> m;
    vector<int> array(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        cin >> array[i];
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = array[i];
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1] + array[j];
            if(dp[i][j] == m)
            {
                flag = true;
                cout << i << "-" << j << endl;
            }
            if(dp[i][j] > m)
            {
                if(dp[i][j] - m < min_)
                {
                    min_ = dp[i][j] - m;
                }
            }
        }
    }
    if(!flag)
    {
        for(int i = 1; i < n; i++)
        {
            for(int j = i; j <= n; j++)
            {
                if(dp[i][j] > m && dp[i][j] - m == min_)    cout << i << "-" << j << endl;
            }
        }
    }
} */

struct Index
{
    int left, right;
};


int main()
{
    int n, m, min_ = 100001;
    cin >> n >> m;
    vector<int> array(n + 1);
    vector<Index> ans;
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        cin >> array[i];
    }
    int left = 1, right = 1;
    int sum = array[1];
    while (right != n + 1)
    {
        // cout << sum << endl;
        if(sum < m)
        {
            right++;
            sum += array[right];
        }
        else if(sum > m)
        {
            if(sum - m < min_)
            {
                ans.clear();
                ans.push_back({left, right});
                min_ = sum - m;
            }
            else if(sum - m == min_)
            {
                ans.push_back({left, right});
            }
            sum -= array[left];
            left++;
        }
        else
        {
            flag = true;
            cout << left << "-" << right << endl;
            right++;
            sum = sum - array[left] + array[right];
            left++;
        } 
    }
    if(!flag)
    {
        for(auto it : ans)
        {
            cout << it.left << "-" << it.right << endl;
        }
    }
}