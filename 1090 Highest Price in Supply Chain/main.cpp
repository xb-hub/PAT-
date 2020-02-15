#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MaxSzie = 100001;
int n, max_num = 0, max_level = 0;
vector<int> edge[MaxSzie];

void dfs(int s, int level)
{
    if(edge[s].size() == 0)
    {
        if(level > max_level)
        {
            max_level = level;
            max_num = 1;
        }
        else if(level == max_level) max_num++;
        return;
    }
    for(int i = 0; i < edge[s].size(); i++)
    {
        dfs(edge[s][i], level + 1);
    }
}

int main()
{
    int index, root;
    double p, r;
    cin >> n >> p >> r;
    for(int i = 0; i < n; i++)
    {
        cin >> index;
        if(index == -1)  root = i;
        else    edge[index].push_back(i);
    }
    dfs(root, 0);
    double ans = p * pow(1 + r / 100, max_level);
    printf("%.2f %d\n", ans, max_num);
}