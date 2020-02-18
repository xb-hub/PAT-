#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const int MaxSize = 100001;
int n;
double p, r, total = 0;
vector<int> net[MaxSize], retailer(MaxSize);

void dfs(int s, int level)
{
    if(net[s].size() == 0)
    {
        total = total + p * pow(1 + r / 100, level) * retailer[s];
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
        if(k == 0)
        {
            cin >> num;
            // is_retailer[i] = true;
            retailer[i] = num;
        }
        else
        {
            for(int j = 0; j < k; j++)
            {
                cin >> child;
                net[i].push_back(child);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f\n", total);
}