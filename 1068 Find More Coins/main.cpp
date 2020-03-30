#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int n, m;
// vector<int> array_(100), ans;

// void dfs(int op, int level, int sum)
// {
//     if(level == n)
//     {
//         return;
//     }
//     if(op == 1)
//     {
//         sum += array_[level];
//         ans.push_back(array_[level]);
//         if(sum > m)
//         {
//             ans.clear();
//             return;
//         }
//         else if(sum == m)
//         {
//             for(auto it : ans)
//             {
//                 cout << it << " ";
//             }
//             cout << endl;
//         }
//     }
//     dfs(1, level + 1, sum);
//     dfs(0, level + 1, sum);
    
// }

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> array_(n);
    for(int i = 0; i < n; i++)
    {
        cin >> array_[i];
    }
    sort(array_.begin(), array_.end());
    int left = 0, right = 0;
    dfs(1, 0, 0);
    dfs(0, 0, 0);
}