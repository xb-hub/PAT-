#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000, MaxSize = 100;
int cmax, n, sp, m, min_send = INF, min_back = INF;
vector<int> w(MaxSize), d(MaxSize, INF), pre[510], tmp_path, ans;
vector<vector<int>> path(MaxSize, vector<int>(MaxSize, INF));
vector<bool> visit(MaxSize);

void Dijkstra(int s = 0)
{
    d[s] = 0;
    for (int i = 0; i <= n; i++)
    {
        int u = -1, min_ = INF;
        for (int j = 0; j <= n; j++)
        {
            if (!visit[j] && d[j] < min_)
            {
                u = j;
                min_ = d[j];
            }
        }
        if (u == -1)
            break;
        visit[u] = true;
        for (int k = 0; k <= n; k++)
        {
            if (!visit[k] && path[u][k] != INF)
            {
                if (path[u][k] + d[u] < d[k])
                {
                    d[k] = path[u][k] + d[u];
                    pre[k].clear();
                    pre[k].push_back(u);
                }
                else if (path[u][k] + d[u] == d[k])
                {
                    pre[k].push_back(u);
                }
            }
        }
    }
}

// void dfs(int s)
// {
//     tmp_path.push_back(s);
//     if(s == 0)
//     {
//         int back = 0, send = 0;
//         for(int i = tmp_path.size() - 1; i >= 0; i--)
//         {
//             int tmp = tmp_path[i];
//             if(w[tmp] > 0)    back += w[tmp];
//             else
//             {
//                 if(back > abs(w[tmp]))
//                 {
//                     back -= abs(w[tmp]);
//                 }
//                 else
//                 {
//                     back = 0;
//                     send += (abs(w[tmp]) - back);
//                 }
//             }
//         }
//         if(send < min_send)
//         {
//             min_send = send;
//             min_back = back;
//             ans = tmp_path;
//         }
//         else if(send == min_send && back < min_back)
//         {
//             min_back = back;
//             ans = tmp_path;
//         }
//         tmp_path.pop_back();
//         return;
//     }
//     for(int i = 0; i < pre[s].size(); i++)
//     {
//         dfs(pre[s][i]);
//     }
//     tmp_path.pop_back();
// }
void dfs(int v)
{
    tmp_path.push_back(v);
    if (v == 0)
    {
        int send = 0, back = 0;
        for (int i = tmp_path.size() - 1; i >= 0; i--)
        {
            int id = tmp_path[i];
            if (w[id] > 0)
            {
                back += w[id];
            }
            else
            {
                if (back > (0 - w[id]))
                {
                    back += w[id];
                }
                else
                {
                    send += ((0 - w[id]) - back);
                    back = 0;
                }
            }
        }
        if (send < min_send)
        {
            min_send = send;
            min_back = back;
            ans = tmp_path;
        }
        else if (send == min_send && back < min_back)
        {
            min_back = back;
            ans = tmp_path;
        }
        tmp_path.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    tmp_path.pop_back();
}

int main()
{
    int s1, s2;
    cin >> cmax >> n >> sp >> m;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> w[i];
        w[i] -= cmax / 2;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s1 >> s2;
        cin >> path[s1][s2];
        path[s2][s1] = path[s1][s2];
    }
    Dijkstra();
    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << d[i] << " ";
    // }
    dfs(sp);
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < pre[i].size(); j++)
    //     {
    //         cout << pre[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << min_send << " " << ans.back();
    for (int i = ans.size() - 2; i >= 0; i--)
    {
        cout << "->" << ans[i];
    }
    cout << " " << min_back << endl;
}