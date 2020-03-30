#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, m, k, v, begin, end;
    cin >> n >> m;
    // vector<vector<int>> graph(n, vector<int>(n, -1));
    vector<int> node[n];
    for(int i = 0; i < m; i++)
    {
        cin >> begin >> end;
        // graph[begin][end] = graph[end][begin] = 1;
        node[begin].push_back(end);
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> v;
        vector<int> array(v);
        map<int, bool> exist;
        bool flag = true;
        for(int j = 0; j <  v; j++)
        {
            cin >> array[j];
            exist[array[j]] = true;
        }
        for(int l = 0; l < n; l++)
        {
            if(exist[l]) continue;
            for(int j = 0; j < node[l].size(); j++)
            {
                if(!exist[node[l][j]])
                {
                    cout << "No" << endl;
                    flag = false;
                    break;
                }
            }
            if(!flag)   break;
        }
        if(flag)    cout << "Yes" << endl;
    }
}