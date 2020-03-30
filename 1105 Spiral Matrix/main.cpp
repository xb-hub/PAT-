#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, tmp_m = 0, tmp_n = 0;
    cin >> n;
    for(int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            tmp_m = n / i;
            tmp_n = i;
        }
    }
    vector<int> array(n);
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    sort(array.begin(), array.end(), cmp);
    // for(auto it : array)
    // {
    //     cout << it << " ";
    // }
    // for(int i = 0; i < )
}