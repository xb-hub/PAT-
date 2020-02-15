#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000, MaxSize = 501;
int n, m, s, d, min_cost = INF;
int city1, city2;
vector<vector<int>> distance_(MaxSize, vector<int>(MaxSize, INF)), cost(MaxSize, vector<int>(MaxSize, 0));
vector<int> c(MaxSize, INF), dis(MaxSize, INF), path[MaxSize], tmp_path, ans;
vector<bool> visit(MaxSize);

/* Dijkstra */
// void Dijkstra(int s)
// {
//     dis[s] = 0;
//     c[s] = 0;
//     for(int i = 0; i < n; i++)
//     {
//         int u = -1, min_ = INF;
//         for(int j = 0; j < n; j++)
//         {
//             if(!visit[j] && dis[j] < min_)
//             {
//                 u = j;
//                 min_ = dis[j];
//             }
//         }
//         if(u == -1)  break;
//         visit[u] = true;
//         for(int k = 0; k < n; k++)
//         {
//             if(!visit[k] && distance_[u][k] != INF)
//             {
//                 if(dis[u] + distance_[u][k] < dis[k])
//                 {
//                     dis[k] = dis[u] + distance_[u][k];
//                     c[k] = c[u] + cost[u][k];
//                     path[k] = u;
//                 }
//                 else if(dis[u] + distance_[u][k] == dis[k])
//                 {
//                     if(c[u] + cost[u][k] < c[k])
//                     {
//                         c[k] = c[u] + cost[u][k];
//                         path[k] = u;
//                     }
//                 }
//             }
//         }
//     }
// }

// void dfs(int d)
// {
//     if(d == s)
//     {
//         cout << d << " ";
//         return;
//     }
//     dfs(path[d]);
//     cout << d << " ";
// }

/* Dijkstra + DFS */
void Dijkstra(int s)
{
    dis[s] = 0;
    c[s] = 0;
    for(int i = 0; i < n; i++)
    {
        int u = -1, min_ = INF;
        for(int j = 0; j < n; j++)
        {
            if(!visit[j] && dis[j] < min_)
            {
                u = j;
                min_ = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int k = 0; k < n; k++)
        {
            if(!visit[k] && distance_[u][k] != INF)
            {
                if(dis[u] + distance_[u][k] < dis[k])
                {
                    dis[k] = dis[u] + distance_[u][k];
                    path[k].clear();
                    path[k].push_back(u);
                }
                else if(dis[u] + distance_[u][k] == dis[k])
                {
                    path[k].push_back(u);
                }
            }
        }
    }
}

void dfs(int d)
{
    tmp_path.push_back(d);
    if(d == s)
    {
        int cost_ = 0;
        for(int i = 1; i < tmp_path.size(); i++)
        {
            cost_ += cost[tmp_path[i]][tmp_path[i -1]]; 
        }
        if(cost_ < min_cost)
        {
            min_cost = cost_;
            ans = tmp_path;
        }
        tmp_path.pop_back();
        return;
    }
    for(int i = 0; i < path[d].size(); i++)
    {
        dfs(path[d][i]);
    }
    tmp_path.pop_back();
}

int main()
{
    cin >> n >> m >> s >> d;
    for(int i = 0; i < m; i++)
    {
        cin >> city1 >> city2;
        cin >> distance_[city1][city2] >> cost[city1][city2];
        distance_[city2][city1] = distance_[city1][city2];
        cost[city2][city1] = cost[city1][city2];
    }
    Dijkstra(s);
    dfs(d);
    for(int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    // cout << dis[d] << " " << c[d];
    cout << dis[d] << " " << min_cost;
}