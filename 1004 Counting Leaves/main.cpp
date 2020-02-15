#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MaxSize = 100;
vector<int> childs[MaxSize];
vector<int> ans(MaxSize);
int max_level = 0;

/* 深度优先遍历 */
void dfs(int c, int level)
{
    if (childs[c].size() == 0)
    {
        max_level = max(max_level, level);
        ans[level]++;
        return;
    }
    else
    {
        for (int i = 0; i < childs[c].size(); i++)
        {
            dfs(childs[c][i], level + 1);
        }
    }
}

/* 广度优先遍历 */
void bfs()
{
    queue<int> q;
    q.push(1);
    int level[MaxSize] = {0};
    level[1] = 1;
    while (!q.empty())
    {
        int front_num = q.front();
        q.pop();
        if (childs[front_num].size() == 0)
        {
            ans[level[front_num]]++;
            max_level = level[front_num];
        }
        else
        {
            for (int i = 0; i < childs[front_num].size(); i++)
            {
                q.push(childs[front_num][i]);
                level[childs[front_num][i]] = level[front_num] + 1;
            }
        }
    }
}

int main()
{
    int n, k, m;
    cin >> n >> m;
    int root, child;
    for (int i = 0; i < m; i++)
    {
        cin >> root >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> child;
            childs[root].push_back(child);
        }
    }
    // dfs(1, 1);
    bfs();
    for (int i = 1; i <= max_level; i++)
    {
        if (i == 1)
        {
            cout << ans[1];
        }
        else
        {
            cout << " " << ans[i];
        }
    }
}
