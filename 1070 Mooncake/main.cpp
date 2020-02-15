#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct MoonCake
{
    double amounts, total, price;
    bool operator < (const MoonCake m) const
    {
        return this->price > m.price;
    }
};

int main()
{
    int n, d;
    double sum = 0;
    cin >> n >> d;
    vector<MoonCake> m(n);
    for(int i = 0; i < n; i++)
    {
        cin >> m[i].amounts;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> m[i].total;
        m[i].price = m[i].total / m[i].amounts;
    }
    sort(m.begin(), m.end());
    // for(int i = 0; i < n; i++)
    // {
    //     cout << m[i].total << " ";
    // }
    for(int i = 0; i < n && d != 0; i++)
    {
        if(m[i].amounts <= d)
        {
            sum += m[i].total;
            d -= m[i].amounts;
        }
        else
        {
            sum += m[i].price * d;
            d = 0;
        }
    }
    printf("%.2f\n", sum);
}