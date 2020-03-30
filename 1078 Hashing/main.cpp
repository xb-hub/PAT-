#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

bool is_prime(int a)
{
    if(a == 1)  return false;
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a % i == 0)  return false;
    }
    return true;
}

int main()
{
    int m, n, num;
    cin >> m >> n;
    while(!is_prime(m)) m++;
    vector<int> exist(m, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        bool flag = false;
        if(i == 0)
        {
            cout << num % m;
            exist[num % m]++;
        }
        else
        {
            for(int i = 0; i < m; i++)
            {
                int tmp = (num + i * i) % m;
                if(exist[tmp] == 0)
                {
                    exist[tmp]++;
                    flag = true;
                    cout << " " << tmp % m;
                    break;
                }
            }
            if(!flag)   cout << " -";
        }
    }
}