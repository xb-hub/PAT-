#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<string>> node(10, vector<string>(2));
vector<int> in_tree, bfs_tree;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int tmp = q.front();
        bfs_tree.push_back(tmp);
        for(int i = 0; i < 2; i++)
        {
            if(node[tmp][i] != "-")   q.push(stoi(node[tmp][i]));
        }
        q.pop();
    }
}

void in_order(string s)
{
    if(s != "-")
    {
        int index = stoi(s);
        in_order(node[index][0]);
        in_tree.push_back(index);
        in_order(node[index][1]);
    }
}

int main()
{
    cin >> n;
    string left, right;
    int exist[10] = {0}, root;
    for(int i = 0; i < n; i++)
    {
        cin >> left >> right;
        // swap(left, right);
        if(left != "-")
        {
            int l = stoi(left);
            exist[l] = 1;
        }
        if(right != "-")
        {
            int r = stoi(right);
            exist[r] = 1;
        }
        node[i][0] = right;
        node[i][1] = left;
    }
    for(int i = 0; i < n; i++)
    {
        if(exist[i] == 0)
        {
            root = i;
            break;
        }
    }
    bfs(root);
    cout << bfs_tree[0];
    for(int i = 1; i < bfs_tree.size(); i++)
    {
        cout << " " << bfs_tree[i];
    }
    cout << endl;
    in_order(to_string(root));
    cout << in_tree[0];
    for(int i = 1; i < in_tree.size(); i++)
    {
        cout << " " << in_tree[i];
    }
}