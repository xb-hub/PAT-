#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct Poly
{
    int exp;
    double coe;
};

bool cmp(Poly a, Poly b)
{
    return a.exp > b.exp;
}

int main()
{
    int n, m;
    cin >> n;
    vector<Poly> poly_1(n);
    for(int i = 0; i < n; i++)
    {
        cin >> poly_1[i].exp >> poly_1[i].coe;
    }
    cin >> m;
    vector<Poly> poly_2(m);
    map<int, double, greater<int>> ans;
    for(int i = 0; i < m; i++)
    {
        cin >> poly_2[i].exp >> poly_2[i].coe;
        for(int j = 0; j < n; j++)
        {
            int exp = poly_2[i].exp + poly_1[j].exp;
            double coe = poly_2[i].coe * poly_1[j].coe;
            ans[exp] += coe;
        }
    }
    int count = 0;
    for(map<int, double>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        if(it->second == 0) count++;
    }
    cout << ans.size() - count;
    for(map<int, double>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        if(it->second != 0) printf(" %d %.1f", it->first, it->second);
    }
}