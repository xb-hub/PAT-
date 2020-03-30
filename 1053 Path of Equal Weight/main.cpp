#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxSize = 100;
int n, m, s;
vector<int> w(MaxSize);
vector<int> node[MaxSize];
vector<vector<int>> ans;

bool cmp(int a, int b)
{
    return w[a] > w[b];
}

void dfs(int no, vector<int> path, int sum)
{
    sum += w[no];
    path.push_back(no);
    // cout << no << " " << sum << endl;
    if(node[no].size() == 0)
    {
        if(sum == s)
        {
            for(int i = 0; i < path.size(); i++)
            {
                if(i != 0)  cout << " ";
                cout << w[path[i]];
            }
            cout << endl;
        }
        return;
    }
    for(int i = 0; i < node[no].size(); i++)
    {
        dfs(node[no][i], path, sum);
    }
}

int main()
{
    int sum = 0;
    cin >> n >> m >> s;
    vector<int> path;
    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int id, k, child;
    for(int i = 0; i < m; i++)
    {
        cin >> id >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> child;
            node[id].push_back(child);
        }
        sort(node[id].begin(), node[id].end(), cmp);
        // for(auto it : node[id])
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
    }
    dfs(0, path, sum);
    // sort(ans.begin(), ans.end());
    // for(int i = 0; i < ans.size(); i++)
    // {
    //     for(int j = 0; j < ans[i].size(); j++)
    //     {
    //         if(j != 0)  cout << " ";
    //         cout << w[ans[i][j]];
    //     }
    //     cout << endl;
    // }
}