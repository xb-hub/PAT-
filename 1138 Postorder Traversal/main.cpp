#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> pre, in;
bool flag = false;

void post(int preL, int preR, int inL, int inR)
{
    if(inL > inR || flag == true)   return;
    int index = inL;
    int root = pre[preL];
    while (in[index] != pre[preL])
    {
        index++;
    }
    int tmp = index - inL;
    post(preL + 1, preL + tmp, inL, index - 1);
    post(preL + tmp + 1, preR, index + 1, inR);
    if(flag == false)
    {
        cout << root << endl;
        flag = true;
    }
}

int main()
{
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    int root = pre[0];
    for(int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    post(0, n - 1, 0, n - 1);
}