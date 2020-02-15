#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n * 1.0); i++)
    {
        if ((n % i) == 0)
        {
            return false;
        }
    }
    return true;
}

/* 字符串 */
// int main()
// {
//     string n;
//     int d;
//     while (true)
//     {
//         cin >> n;
//         if (stoi(n) < 0)
//             break;
//         cin >> d;
//         int num = stoi(n), i = 0, r_num = 0;
//         string r_s = "";
//         if (!is_prime(num))
//         {
//             cout << "No" << endl;
//             continue;
//         }
//         if (d != 10)
//         {
//             int tmp = num;
//             while (tmp)
//             {
//                 r_s += to_string(tmp % d);
//                 tmp /= d;
//             }
//             for (auto it = r_s.rbegin(); it != r_s.rend(); it++)
//             {
//                 r_num += (*it - '0') * pow(d, i++);
//             }
//         }
//         else
//         {
//             num = stoi(n);
//             reverse(n.begin(), n.end());
//             r_num = stoi(n);
//         }
//         // cout << num << " " << r_num << endl;
//         if (is_prime(r_num))
//         {
//             cout << "Yes" << endl;
//         }
//         else
//         {
//             cout << "No" << endl;
//         }
//     }
// }

/* 数组 */
int main()
{
    int n, d;
    while (true)
    {
        cin >> n;
        if (n < 0)
            break;
        cin >> d;
        int l = 0, r_num = 0;
        int digit[100];
        if (!is_prime(n))
        {
            cout << "No" << endl;
            continue;
        }
        int tmp = n;
        do
        {
            digit[l++] = tmp % d;
            tmp /= d;
        } while (tmp != 0);
        int i = l - 1;
        for(int j = 0; j < l; j++)
        {
            r_num += digit[j] * pow(d, i--);
        }
        // cout << n << " " << r_num << endl;
        if (is_prime(r_num))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}