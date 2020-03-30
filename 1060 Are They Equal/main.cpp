#include <iostream>
using namespace std;

string solve(string s, int n)
{
    int i = 0;
    string ans = "0.";
    size_t tmp = s.find('.');
    while((s[i] == '0' || s[i] == '.'))
    {
        i++;
    }
    s = s.substr(i, s.size() - i);
    if(tmp < i)
    {
        ans += s;
        if(n - s.size() > 0)
        {
            for(int j = 0; j < n - s.size(); j++)
            {
                ans += "0";
            }
        }
        if((i - tmp - 1) == 0)  ans += ("*10^0");
        else    ans += ("*10^-" + to_string(i - tmp - 1));
        return ans;
    }
    tmp = s.find('.');
    // cout << n << " " << s.size() << endl;
    if(tmp != string::npos)
    {
        if(tmp >= n)
        {
            ans += (s.substr(0, n) + "*10^" + to_string(tmp));
        }
        else
        {
            if(n - s.size() + 1 > 0)
            {
                for(int j = 0; j < n - s.size() + 1; j++)   s += "0";
            }
            ans += (s.substr(0, tmp) + s.substr(tmp + 1, n - tmp) + "*10^" + to_string(tmp));
        }
    }
    else
    {
        for(int j = 0; j < n - s.size(); j++)   s += "0";
        ans += (s.substr(0, n) + "*10^" + to_string(s.size()));
    }
    return ans;
}

int main()
{
    int n;
    string a, b, ans;
    cin >> n >> a >> b;
    a = solve(a, n);
    b = solve(b, n);
    // cout << a << endl << b << endl;
    if(a == b)
    {
        cout << "YES" << " " << a << endl;
    }
    else
    {
        cout << "NO" << " " << a << " " << b << endl;
    }
}