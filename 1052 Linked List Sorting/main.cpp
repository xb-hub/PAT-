#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int address, data, next;
    bool flag = false;
    bool operator< (const Node n) const
    {
        return !this->flag || !n.flag ? this->flag > n.flag : this->data < n.data;
    }
};


int main()
{
    const int MaxSize = 100001;
    int n, head, address, data, next, count = 0;
    cin >> n >> head;
    vector<Node> node(MaxSize);
    vector<int> list;
    for(int i = 0; i < n; i++)
    {
        cin >> address >> data >> next;
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    while (head != -1)
    {
        count++;
        node[head].flag = true;
        head = node[head].next;
    }
    if(count == 0) 
    {
        printf("0 -1");
        return 0;
    }
    sort(node.begin(), node.end());
    printf("%d %05d\n", count, node.front().address);
    for(int i = 0; i < count - 1; i++)
    {
        printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
    }
    printf("%05d %d -1\n", node[count - 1].address, node[count - 1].data);
}