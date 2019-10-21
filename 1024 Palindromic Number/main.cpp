#include <iostream>
#include <algorithm>
using namespace std;

string add(string s, string re_s)
{
    int carry = 0;
    for(int i = 0; i < s.size(); i++)
    {
        s[i] = s[i] + re_s[i] + carry - '0';
        carry = 0;
        if(s[i] > '9')
        {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry != 0)  s += '1';
    return s;
}

int main()
{
    int k, i;
    string n, num;
    cin >> n >> k;
    for(i = 0; i < k; i++)
    {
        num = n;
        reverse(num.begin(), num.end());
        if(num == n)
        {
            break;
        }
        n = add(n, num);
    }
    reverse(n.begin(), n.end());
    cout << n << endl << i;
}