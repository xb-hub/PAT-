#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    int next;
};


int main()
{
    const int MaxSize = 100000;
    int origin, address, data, next, n, k;
    cin >> origin >> n >> k;
    vector<Node> node(MaxSize);
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        cin >> address >> data >> next;
        node[address].data = data;
        node[address].next = next;
    }
    int tmp = origin;
    while(tmp != -1)
    {
        a.push_back(tmp);
        tmp = node[tmp].next;
    }
    // for(int i = 0; i < n; i++)
    // {
    //     cout << node[a[i]].data << endl;
    // }
    for(int i = 0; i < a.size() / k; i++)
    {
        reverse(a.begin() + i * k, a.begin() + (i + 1) * k);
    }
    for(int i = 0; i < a.size() - 1; i++)
    {
        // cout << a[i] << " " << node[a[i]].data << " " << a[i + 1] << endl;
        printf("%05d %d %05d\n", a[i], node[a[i]].data, a[i + 1]);
    }
    // cout << a[n - 1] << " " << node[a[n - 1]].data << " " << "-1" << endl;
    printf("%05d %d -1\n", a.back(), node[a.back()].data);
}