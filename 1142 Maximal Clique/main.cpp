#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v, e, m, k, begin, end;
    cin >> v >> e;
    vector<vector<int> > graph(v + 1, vector<int>(v + 1, -1));
    for(int i = 0; i < e; i++)
    {
        cin >> begin >> end;
        graph[begin][end] = 1;
        graph[end][begin] = 1;
    }
    // for(int i = 1; i <= v; i++)
    // {
    //     for(int j = 1; j <= v; j++)
    //     {
    //         printf("%4d ", graph[i][j]);
    //     }
    //     cout << endl;
    // }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> k;
        vector<int> array(k), exist(v + 1, 0);
        bool flag = true, is_max = true;
        for(int j = 0; j < k; j++)
        {
            cin >> array[j];
            exist[array[j]]++;
        }
        for(int j = 0; j < k - 1; j++)
        {
            if(flag == false)   break;
            for(int l = j + 1; l < k; l++)
            {
                // cout << array[j] << " " << array[l] << endl;
                if(graph[array[j]][array[l]] == -1)
                {
                    cout << "Not a Clique" << endl;
                    flag = false;
                    break;
                }
            }
        }
        if(flag == false)   continue;
        for(int j = 1; j <= v; j++)
        {
            if(exist[j] == 0)
            {
                for(int l = 0; l < k; l++)
                {
                    if(graph[j][array[l]] == -1)
                    {
                        break;
                    }
                    if(l == k - 1)  is_max = false;
                }
                if(!is_max)
                {
                    cout << "Not Maximal" << endl;
                    break;
                }
            }
        }
        if(is_max)  cout << "Yes" << endl;
    }
}