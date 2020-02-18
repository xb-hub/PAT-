#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, begin, end, sum = 0;
    cin >> n;
    vector<int> distance(n), tmp(n);
    for(int i = 0; i < n; i++)
    {
        cin >> distance[i];
        sum += distance[i];
        tmp[i] = sum;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> begin >> end;
        if(begin > end) swap(begin, end);
        int d = tmp[end - 2] - tmp[begin - 2];
        cout << min(d, sum - d) << endl;
    }
}