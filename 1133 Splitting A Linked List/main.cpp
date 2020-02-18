#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data, next;
};


int main()
{
    const int MaxSize = 100001;
    vector<Node> node(MaxSize);
    int origin, n, k, address, data, next;
    cin >> origin >> n >> k;
    vector<int> list, tmp_list;
    for(int i = 0; i < n; i++)
    {
        cin >> address >> data >> next;
        node[address].data = data;
        node[address].next = next;
    }
    while (origin != -1)
    {
        list.push_back(origin);
        origin = node[origin].next;
    }
    for(auto it : list)
    {
        if(node[it].data < 0)   tmp_list.push_back(it);   
    }
    for(auto it : list)
    {
        if(node[it].data >= 0 && node[it].data <= k) tmp_list.push_back(it);
    }
    for(auto it : list)
    {
        if(node[it].data > k)    tmp_list.push_back(it);
    }
    for(int i = 0; i < tmp_list.size() - 1; i++)
    {
        printf("%05d %d %05d\n", tmp_list[i], node[tmp_list[i]].data, tmp_list[i + 1]);
    }
    printf("%05d %d %s\n", tmp_list.back(), node[tmp_list.back()].data, "-1");
}