#include <iostream>
#include <vector>
using namespace std;

const int INF = 1000000000, MaxSize = 501;
int cmax, n, sp, m, min_send = INF, min_back = INF;
vector<int> w(MaxSize), d(MaxSize, INF), pre[MaxSize], tmp_path, ans;
vector<vector<int>> path(MaxSize, vector<int>(MaxSize, INF));
vector<bool> visit(MaxSize);

void Dijkstra(int s)
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

void dfs(int s)
{
    tmp_path.push_back(s);
    if(s == 0)
    {
        int back = 0, send = 0;
        for(int i = tmp_path.size() - 1; i >= 0; i--)
        {
            int tmp = tmp_path[i];
            if(w[tmp] > 0)    back += w[tmp];
            else
            {
                if(back > abs(w[tmp]))
                {
                    back -= abs(w[tmp]);
                }
                else
                {
                    send += (abs(w[tmp]) - back);
                    back = 0;
                }
            }
        }
        if(send < min_send)
        {
            min_send = send;
            min_back = back;
            ans = tmp_path;
        }
        else if(send == min_send && back < min_back)
        {
            min_back = back;
            ans = tmp_path;
        }
        tmp_path.pop_back();
        return;
    }
    for(int i = 0; i < pre[s].size(); i++)
    {
        dfs(pre[s][i]);
    }
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
    Dijkstra(0);
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
    cout << min_send << " 0";
    for (int i = ans.size() - 2; i >= 0; i--)
    {
        cout << "->" << ans[i];
    }
    cout << " " << min_back << endl;
}