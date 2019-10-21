#include <iostream>
#include <algorithm>
using namespace std;

string add(string s, string re_s)
{
    int carry = 0;
    string ans_s = "";
    for(int i = 0; i < s.size(); i++)
    {
        int temp = s[i] - '0' + re_s[i] - '0';
        ans_s += to_string(temp % 10 + carry);
        carry = temp / 10;
    }
    if(carry != 0)  ans_s += '1';
    reverse(ans_s.begin(), ans_s.end());
    return ans_s;
}

int main()
{
    int k, i;
    string n;
    cin >> n >> k;
    for(i = 0; i < k; i++)
    {
        string num = n;
        reverse(num.begin(), num.end());
        if(num == n || i == k)
        {
            break;
        }
        n = add(n, num);
    }
    cout << n << endl << i;
}