#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MaxSize = 101;
int n;
vector<int> node[MaxSize], tree, ans(MaxSize);

void pre_order(int s)
{
    if(s != -1)
    {
        pre_order(node[s][0]);
        tree.push_back(s);
        pre_order(node[s][1]);
    }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    cout << ans[s];
    while(!q.empty())
    {
        int tmp = q.front();
        if(tmp) cout << " " << ans[tmp];
        if(node[tmp][0] != -1)    q.push(node[tmp][0]);
        if(node[tmp][1] != -1)    q.push(node[tmp][1]);
        q.pop();
    }
}

int main()
{
    int left, right;
    cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++)
    {
        cin >> left >> right;
        node[i].push_back(left);
        node[i].push_back(right);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    pre_order(0);
    int index = 0;
    for(auto it : tree)
    {
        // cout << it << " ";
        ans[it] = array[index++];
    }
    bfs(0);
}