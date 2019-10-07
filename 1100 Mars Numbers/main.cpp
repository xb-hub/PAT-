#include <iostream>
#include <algorithm>
using namespace std;

string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                    "jly",  "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"####", "tam", "hel", "maa", "huh", "tou", "kes",
                    "hei",  "elo", "syy", "lok", "mer", "jou"};

int main()
{
    int n;
    cin >> n;
    getchar();
    string s;
    for(int i = 0; i < n; i++)
    {
        getline(cin, s);
        if(isdigit(s[0]))
        {
            int temp = stoi(s);
            if((temp >= 13))
            {
                if((temp % 13) != 0)   cout << b[temp / 13] << " " << a[temp % 13] << endl;
                else    cout << b[temp / 13] << endl;
            }
            else
            {
                cout << a[temp] << endl;
            } 
        }
        else
        {
            string high_digit = s.substr(0, 3);
            int ans = 0;
            if(s.size() > 3)
            {
                string low_digit = s.substr(4, 3);
                for (int i = 0; i < 13; i++)
                {
                    if(high_digit == b[i])
                    {
                        ans += i * 13; 
                    }
                    if(low_digit == a[i])
                    {
                        ans += i;
                    }
                }
            }
            else
            {
                for (int i = 0; i < 13; i++)
                {
                    if(high_digit == a[i])
                    {
                        ans = i;
                    }
                    if(high_digit == b[i])
                    {
                        ans = i * 13;
                    }
                }
            }
            cout << ans << endl;   
        }
    }
}
