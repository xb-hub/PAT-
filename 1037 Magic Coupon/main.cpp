#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int c, p;
    cin >> c >> p;
    int b_c, b_p;
    vector<int> l_c, l_p;
    for(int i = 0; i < c; i++)
    {
        cin >> b_c;
        l_c.push_back(b_c);
    }
    for(int j = 0; j < p; j++)
    {
        cin >> b_p;
        l_p.push_back(b_p);
    }
    sort(l_c.begin(), l_c.end(), cmp);
    sort(l_p.begin(), l_p.end(), cmp);
    if(c > p)
    {
        for(vector<int>::iterator it = l_p.begin(); it != l_p.end(); it++)
        {
            if(*it < 0)
            {
                    l_p.insert(it, c - p, 0);
            }
        }
    }
    else
    {
        for(vector<int>::iterator it = l_c.begin(); it != l_c.end(); it++)
        {
            if(*it < 0)
            {
                    l_c.insert(it, p - c, 0);
            }
        }
    }
    int size = max(c, p), ans = 0;
    for(int i = 0; i < size; i++)
    {
        cout << l_c[i] << " ";
    }
    for(int i = 0; i < size; i++)
    {
        ans += l_c[i] * l_p[i];
    }
    cout << ans << endl;
}