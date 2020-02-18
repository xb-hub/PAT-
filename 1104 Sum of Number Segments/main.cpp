#include <iostream>
#include <vector>
using namespace std;

/** 
 * 动态规划
 * 内存超限
 * /
int main()
{
    int n;
    double sum = 0;
    cin >> n;
    vector<double> array(n, 0);
    vector<vector<double>> dp(n, vector<double>(n));
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = array[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1] + array[j];
        }
    }
    for(int i = 0; i < dp.size(); i++)
    {
        for(int j = 0; j < dp[0].size(); j++)
        {
            sum += dp[i][j];
        }
    }
    printf("%.2f\n", sum);
}

/* 数学 */
int main()
{
    int n;
    cin >> n;
    double tmp, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
        sum += tmp * i * (n - i + 1);
    }
    printf("%.2f\n", sum);
}