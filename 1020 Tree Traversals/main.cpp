#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *lchild;
    node *rchild;
};

vector<int> post, in;

node* creat(int postL, int postR, int inL, int inR)
{
    if(postL > postR)    return NULL;
    int index;
    for(index = inL; index <= inR; index++)
    {
        if(in[index] == post[postR]) break;
    }
    int num = index - inL;
    node* root = new node;
    root->data = post[postR];
    root->lchild = creat(postL, postL + num - 1, inL, index - 1);
    root->rchild = creat(postL + num, postR - 1, index + 1, inR);
    return root;
}

void display(node *root, int n)
{
    int count = 0;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *now = q.front();
        q.pop();
        cout << now->data;
        count++;
        if (count < n)
            cout << " ";
        if (now->lchild != NULL)
            q.push(now->lchild);
        if (now->rchild != NULL)
            q.push(now->rchild);
    }
}

int main()
{
    int n;
    cin >> n;
    post.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    node *root = creat(0, n - 1, 0, n - 1);
    display(root, n);
}