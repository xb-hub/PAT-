#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(i < n / 2)
        {
            sum -= v[i];
        }
        else
        {
            sum += v[i];
        }
    }
    if(n & 1)   cout << "1 " << sum << endl;
    else    cout << "0 " << sum << endl;
}