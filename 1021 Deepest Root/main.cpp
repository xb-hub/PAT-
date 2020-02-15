#include <iostream>
#include <vector>
using namespace std;

const int MaxSize = 10000;
int n;
vector<vector<int>> edge(MaxSize, vector<int>(MaxSize, 0));
vector<bool> visit(MaxSize);

void dfs(int s, int level)
{
    visit[s] = true;
    for(int i = 0; i < n; i++)
    {
        if(!visit[s] && edge[s][i] != 0)
        {
            dfs(i, level + 1);
        }
    }
}

int main()
{
    int node1, node2;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> node1 >> node2;
        edge[node1][node2] = 1;
        edge[node2][node1] = 1;
    }
}