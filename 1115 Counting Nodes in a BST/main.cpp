#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;
    Node() : data(0), lchild(NULL), rchild(NULL){}
};

int max_level = 0;
vector<int> ans(1000, 0);

void insert(Node* &root, int data)
{
    if(root == NULL)
    {
        root = new Node();
        root->data = data;
        return;
    }
    if(data <= root->data)
    {
        insert(root->lchild, data);
    }
    if(data > root->data)
    {
        insert(root->rchild, data);
    }
}

void creat(Node* &root, vector<int> array)
{
    for(int i = 0; i < array.size(); i++)
    {
        insert(root, array[i]);
    }
}

void dfs(Node* s, int level)
{
    ans[level]++;
    if(level > max_level)   max_level = level;
    if(s->lchild != NULL)   dfs(s->lchild, level + 1);
    if(s->rchild != NULL)   dfs(s->rchild, level + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> node(n);
    for(int i = 0; i < n; i++)
    {
        cin >> node[i];
    }
    Node* root = NULL;
    creat(root, node);
    dfs(root, 0);
    cout << ans[max_level] << " + " << ans[max_level - 1] << " = " << ans[max_level] + ans[max_level - 1] << endl;
}