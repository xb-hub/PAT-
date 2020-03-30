#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b)
{
    return a * b < 0 ? a > b : abs(a) > abs(b);
}

int main()
{
    int c, p, count_c = 0, count_p = 0, sum = 0;
    cin >> c;
    vector<int> array_c(c);
    for(int i = 0; i < c; i++)
    {
        cin >> array_c[i];
        if(array_c[i] > 0)  count_c++;
    }
    cin >> p;
    vector<int> array_p(p);
    for(int i = 0; i < p; i++)
    {
        cin >> array_p[i];
        if(array_p[i] > 0)  count_p++;
    }
    sort(array_c.begin(), array_c.end(), cmp);
    sort(array_p.begin(), array_p.end(), cmp);
    int count = min(count_c, count_p);
    for(int i = 0; i < count; i++)
    {
        sum += array_c[i] * array_p[i];
    }
    int tmp = min(array_c.size() - count_c, array_p.size() - count_p);
    for(int i = 0; i < tmp; i++)
    {
        sum += array_c[count_c + i] * array_p[count_p + i];
    }
    cout << sum << endl;
}