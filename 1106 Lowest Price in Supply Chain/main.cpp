#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MaxSize = 100001;
int n, min_level = MaxSize, count_ = 0;
double p, r;
vector<int> net[MaxSize];

void dfs(int s, int level)
{
    if(net[s].size() == 0)
    {
        if(level < min_level)
        {
            count_ = 1;
            min_level = level;
        }
        else if(level == min_level)
        {
            count_++;
        }
        return;
    }
    for(int i = 0; i < net[s].size(); i++)
    {
        dfs(net[s][i], level + 1);
    }
}

int main()
{
    int k, child, num;
    cin >> n >> p >> r;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            cin >> child;
            net[i].push_back(child);
        }
    }
    dfs(0, 0);
    printf("%.4f %d\n", p * pow(1 + r / 100, min_level), count_);
}