#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k, begin, end;
    cin >> n >> m;
    vector<int> graph[1001];
    vector<int> inDegree(n + 1, 0), array(n), ans;
    for(int i = 0; i < m; i++)
    {
        cin >> begin >> end;
        graph[begin].push_back(end);
        inDegree[end]++;
    }
    cin >> k;
    vector<int> tmp(n + 1);
    for(int i = 0; i < k; i++)
    {
        tmp = inDegree;
        for(int j = 0; j < n; j++)
        {
            cin >> array[j];
        }
        for(int j = 0; j < array.size(); j++)
        {
            if(tmp[array[j]] != 0)
            {
                ans.push_back(i);
                break;
            }
            else
            {
                for(auto it : graph[array[j]])
                {
                    tmp[it]--;
                }
            }
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        if(i != 0)  cout << " ";
        cout << ans[i];
    }
}