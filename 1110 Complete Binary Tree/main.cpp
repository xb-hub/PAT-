#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> node(20, vector<int>(2));

/* 广度优先，层次遍历 */
int leaf;
bool bfs(int root)
{
    queue<int> q;
    q.push(root);
    bool right_exist = false;
    while (!q.empty())
    {
        leaf = q.front();
        // cout << leaf << " ";
        if(node[leaf][0] == -1 && node[leaf][1] != -1)   return false;
        if(node[leaf][0] != -1)  q.push(node[leaf][0]);
        if(node[leaf][1] != -1)
        {
            q.push(node[leaf][1]);
            right_exist = true;
        }
        else    right_exist = false;
        if(right_exist == false)
        {
            q.pop();
            while (!q.empty())
            {
                leaf = q.front();
                if(node[leaf][0] != -1 || node[leaf][1] != -1)
                {
                    return false;
                }
                q.pop();
            }
        }
        if(!q.empty())  q.pop();
    }
    return true;
}

/* 深度优先，遍历出最大下标值，与n比较 */
int maxn = 0, ans;
void dfs(int root, int index)
{
    if(index > maxn)
    {
        maxn = index;
        ans = root;
    }
    if(node[root][0] != -1) dfs(node[root][0], 2 * index + 1);
    if(node[root][1] != -1) dfs(node[root][1], 2 * index + 2);
}

int main()
{
    int n, root;
    cin >> n;
    vector<int> child(n, 0);
    string left, right;
    for(int i = 0; i < n; i++)
    {
        cin >> left >> right;
        if(left == "-") node[i][0] = -1;
        else
        {
            int tmp = stoi(left);
            node[i][0] = tmp;
            child[tmp]++;
        }
        if(right == "-") node[i][1] = -1;
        else
        {
            int tmp = stoi(right);
            node[i][1] = tmp;
            child[tmp]++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(child[i] == 0)   root = i;
    }
    // if(bfs(root))  cout << "YES " << leaf << endl;
    // else    cout << "NO " << root << endl;
    dfs(root, 0);
    if(maxn == n - 1)   cout << "YES " << ans << endl;
    else    cout << "NO " << root << endl;
}