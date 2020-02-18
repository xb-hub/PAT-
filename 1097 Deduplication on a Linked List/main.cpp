#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    int next;
};


int main()
{
    const int MaxSize = 100001;
    int head, n, address;
    cin >> head >> n;
    vector<Node> node(MaxSize);
    unordered_map<int, bool> exist;
    for(int i = 0; i < n; i++)
    {
        cin >> address;
        cin >> node[address].data >> node[address].next;
    }
    vector<int> list, remove_list;
    while (head != -1)
    {
        if(exist[abs(node[head].data)])
        {
            remove_list.push_back(head);
            head = node[head].next;
            continue;
        }
        list.push_back(head);
        exist[abs(node[head].data)] = true;
        head = node[head].next;
    }
    for(int i = 0; i < list.size() - 1; i++)
    {
        printf("%05d %d %05d\n", list[i], node[list[i]].data, list[i + 1]);
    }
    printf("%05d %d %s\n", list.back(), node[list.back()].data, "-1");
    if(remove_list.size() != 0)
    {
        for(int i = 0; i < remove_list.size() - 1; i++)
        {
            printf("%05d %d %05d\n", remove_list[i], node[remove_list[i]].data, remove_list[i + 1]);
        }
        printf("%05d %d %s\n", remove_list.back(), node[remove_list.back()].data, "-1");
    }
}