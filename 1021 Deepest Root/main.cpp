#include <iostream>
#include <vector>
using namespace std;

const int MaxSize = 1000000;
int n, ans = 0, max_level = 0;
vector<int> edge[MaxSize];
vector<bool> visit(MaxSize);

void dfs(int s, int level)
{
    visit[s] = true;
    max_level = max(max_level, level);
    for(int i = 0; i < edge[s].size(); i++)
    {
        if(!visit[edge[s][i]])
        {
            dfs(edge[s][i], level + 1);
        }
    }
}

int main()
{
    int node1, node2, count = 0; 
    cin >> n;
    vector<int> dp(n + 1);
    for(int i = 0; i < n - 1; i++)
    {
        cin >> node1 >> node2;
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!visit[i])
        {
            count++;
            dfs(i, 0);
        }
    }
    if(count > 1)
    {
        printf("Error: %d components\n", count);
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            max_level = 0;
            fill(visit.begin(), visit.end(), false);
            dfs(i, 0);
            dp[i] = max_level;
            ans = max(ans, max_level);
        }
        for(int i = 1; i < dp.size(); i++)
        {
            if(dp[i] == ans)
            {
                cout << i << endl;
            }
        }
    }
}