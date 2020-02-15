#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m, k, q, c;
    cin >> n >> m >> k >> q;
    vector<int> times(k), ans(k);
    vector<queue<int>> qu(n);
    for(int i; i < k; i++)
    {
        cin >> times[k];
    }
    int tmp = 0;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            qu[j].push(times[tmp++]);
        }
    }
    for(int i = 0; i < q; i++)
    {
        cin >> c;
    }
}