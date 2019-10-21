#include <iostream>
#include <map>
using namespace std;

int main()
{
    int k1, k2, exp, count = 0;
    double coe;
    map<int, double, greater<int>> result;
    cin >> k1;
    for (int i = 0; i < k1; i++)
    {
        cin >> exp >> coe;
        result[exp] += coe;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++)
    {
        cin >> exp >> coe;
        result[exp] += coe;
    }
    for (map<int, double>::iterator it = result.begin(); it != result.end(); it++)
    {
        if (it->second != 0.0)
        {
            count++;
        }
    }
    cout << count;
    for (map<int, double>::iterator it = result.begin(); it != result.end(); it++)
    {
        if (it->second != 0.0)
        {
            printf(" %d %.1f", it->first, it->second);
        }
    }
}