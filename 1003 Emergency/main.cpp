#include <iostream>
#include <vector>
// #define INF 1000000000
using namespace std;

// void Dijkstra(int s, int n, vector<vector<int>> path, vector<int> teams,
//                 vector<bool> &visit, vector<int> &d, vector<int> &num, vector<int> &w)
// {
//       d[s] = 0;
//       w[s] = teams[s];
//       num[s] = 1;
//       for(int i = 0; i < n; i++)
//       {
//           int u = -1, min = INF;
//           for(int j = 0; j < n; j++)
//           {
//               if(visit[j] == false && d[j] < min)
//               {
//                   u = j;
//                   min = d[j];
//               }
//           }
//           if(u == -1)   break;
//           visit[u] = true;
//           for(int k = 0; k < n; k++)
//           {
//               if(visit[k] == false && path[u][k] != INF)
//               {
//                   if(d[u] + path[u][k] < d[k])
//                   {
//                       d[k] = d[u] + path[u][k];
//                       w[k] = w[u] + teams[k];
//                       num[k] = num[u];
//                   }
//                   else if(d[u] + path[u][k] == d[k])
//                   {
//                       if(w[u] + teams[k] > w[k])
//                       {
//                           w[k] = w[u] + teams[k];
//                       }
//                       num[k] += num[u];
//                   }
//               }
//           }
//       }
// }

// int main()
// {
//     int n, m, c1, c2, begin, end;
//     cin >> n >> m >> c1 >> c2;
//     vector<int> teams(n), d(n, INF), num(n, 0), w(n, 0);
//     vector<bool> visit(n);
//     vector<vector<int>> path(m, vector<int>(m, INF));
//     for(int i = 0; i < n; i++)
//     {
//         cin >> teams[i];
//     }
//     for(int i = 0; i < m; i++)
//     {
//         cin >> begin >> end;
//         cin >> path[begin][end];
//         path[end][begin] = path[begin][end];
//     }
//     // for(int i = 0; i < m; i++)
//     // {
//     //     for(int j = 0; j < m; j++)
//     //     {
//     //         cout << path[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     Dijkstra(c1, n, path, teams, visit, d, num, w);
//     cout << num[c2] << " " << w[c2];
//     return 0;
// }

int n, m, c1, c2, begin_, end_;
const int MaxSize = 501, INF = 1000000000;
vector<vector<int>> path(MaxSize, vector<int>(MaxSize, INF));
vector<int> team(MaxSize, 0), d(MaxSize, INF), num(MaxSize, 0), w(MaxSize, 0);
vector<bool> visit(MaxSize);

void Dijkstra(int s)
{
    d[s] = 0;
    w[s] = team[s];
    num[s] = 1;
    for (int i = 0; i < n; i++)
    {
        int u = -1, min_ = INF;
        for(int j = 0; j < n; j++)
        {
            if (!visit[j] && d[j] < min_)
            {
                u = j;
                min_ = d[j];
            }
        }
        if(u == -1)  break;
        visit[u] = true;
        for (int k = 0; k < n; k++)
        {
            if (!visit[k] && path[u][k] != INF)
            {
                if (d[u] + path[u][k] < d[k])
                {
                    d[k] = d[u] + path[u][k];
                    w[k] = w[u] + team[k];
                    num[k] = num[u];
                }
                else if (d[u] + path[u][k] == d[k])
                {
                    num[k] += num[u];
                    if (w[u] + team[k] > w[k])
                    {
                        w[k] = w[u] + team[k];
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++)
    {
        cin >> team[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> begin_ >> end_;
        cin >> path[begin_][end_];
        path[end_][begin_] = path[begin_][end_];
    }
    Dijkstra(c1);
    cout << num[c2] << " " << w[c2];
}