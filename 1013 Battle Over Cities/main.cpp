#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
const int MaxSize = 1001;
vector<vector<int>> path(MaxSize, vector<int>(MaxSize, 0));
vector<bool> visit(MaxSize);

/* 邻接矩阵 */
// void dfs(int c)
// {
//     visit[c] = true;
//     for(int i = 1; i <= n; i++)
//     {
//         if(!visit[i] && path[c][i] == 1)
//         {
//             dfs(i);
//         }
//     }
// }

// int main()
// {
//     int c1, c2, concern, count;
//     cin >> n >> m >> k;
//     for(int i = 0; i < m; i++)
//     {
//         cin >> c1 >> c2;
//         path[c1][c2] = 1;
//         path[c2][c1] = 1;
//     }
//     for(int i = 0; i < k; i++)
//     {
//         fill(visit.begin(), visit.end(), false);
//         cin >> concern;
//         count = 0;
//         visit[concern] = true;
//         for(int i = 1; i <= n; i++)
//         {
//             if(!visit[i])
//             {
//                 dfs(i);
//                 count++;
//             }
//         }
//         cout << count - 1 << endl;
//     }
// }

/* 邻接表 */
void dfs(int c)
{
    visit[c] = true;
    for(int j = 0; j < path[c].size(); j++)
    {
        int node = path[c][j];
        if(!visit[node])
        {
            dfs(node);
        }
    }
}

int main()
{
    // cin >> n >> m >> k;
    scanf("%d %d %d", &n, &m, &k);
    int c1, c2, concern, count;
    for(int i = 0; i < m; i++)
    {
        // cin >> c1 >> c2;
        scanf("%d %d", &c1, &c2);
        path[c1].push_back(c2);
        path[c2].push_back(c1);
    }
    for(int i = 1; i <= k; i++)
    {
        fill(visit.begin(), visit.end(), false);
        count = 0;
        // cin >> concern;
        scanf("%d", &concern);
        visit[concern] = true;
        for(int j = 1; j <= n; j++)
        {
            if(!visit[j])
            {
                dfs(j);
                count++;
            }
        }
        printf("%d\n", count - 1);
    }
}