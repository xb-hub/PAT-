#include <iostream>
#include <unordered_map>
#include <vector>
#define MaxSize 100001
using namespace std;

struct Node
{
    char data;
    int next;
} node[MaxSize];


int main()
{
    int word1, word2, n, address;
    cin >> word1 >> word2 >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> address;
        cin >> node[address].data >> node[address].next;
    }
    bool exist[MaxSize];
    int tmp1 = word1, tmp2 = word2;
    while(tmp1 != -1)
    {
        exist[tmp1] = true;
        tmp1 = node[tmp1].next;
    }
    while(tmp2 != -1)
    {
        if(exist[tmp2])
        {
            break;
        }
        tmp2 = node[tmp2].next;
    }
    if(tmp2 != -1)
    {
        printf("%05d\n", tmp2);
    }
    else
    {
        printf("-1\n");
    }
}