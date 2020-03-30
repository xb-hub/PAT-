#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, m, k, num;
    scanf("%d", &n);
    vector<set<int>> array(n + 1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &num);
            array[i].insert(num);
        }
    }
    scanf("%d", &k);
    int set1, set2;
    for(int i = 0; i < k; i++)
    {
        double nc = 0, nt;
        scanf("%d %d", &set1, &set2);
        for(auto it : array[set1])
        {
            if(array[set2].find(it) != array[set2].end())
            {
                nc++;
            }
        }
        nt = array[set1].size() + array[set2].size() - nc;
        printf("%.1f%s\n", nc / nt * 100, "%");
    }
}