#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, max_level = 1;
vector<int> node[101], count_(101);
queue<int> q;

// void bfs()
// {
//     q.push(1);
//     while (!q.empty())
//     {
//         int tmp = q.front();
//         for(int i = 0; i < node[tmp].size(); i++)
//         {
//             q.push(node[tmp][i]);
//         }
//         q.pop();
//     }
// }

void dfs(int s, int level)
{
    count_[level]++;
    if(node[s].size() == 0)
    {
        if(level > max_level)   max_level = level;
    }
    for(int i = 0; i < node[s].size(); i++)
    {
        dfs(node[s][i], level + 1);
    }
}

int main()
{
    int m, id, k, child, max_ = 0, ans;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> id >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> child;
            node[id].push_back(child);
        }
    }
    dfs(1, 1);
    for(int i = 1; i <= max_level; i++)
    {
        if(count_[i] > max_)
        {
            max_ = count_[i];
            ans = i;
        }
    }
    cout << max_ << " " << ans << endl;
}