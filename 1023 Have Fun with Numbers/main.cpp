#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    string num;
    map<char, int> exist;
    cin >> num;
    int carry = 0;
    for(int i = num.size() - 1; i >= 0; i--)
    {
        exist[num[i]]++;
        int temp = (num[i] - '0') * 2 + carry;
        carry = temp / 10;
        temp %= 10;
        num[i] = temp + '0';
        exist[num[i]]--;
    }
    if(carry)
    {
        cout << "No" << endl << "1" << num;
        return 0;
    }
    bool flag = true;
    for(map<char, int>::iterator it = exist.begin(); it != exist.end(); it++)
    {
        // cout << it->second << " ";
        if(it->second != 0)
        {
            flag = false;
            break;
        }
    }
    string ans = flag ? "Yes" : "No";
    cout << ans << endl << num;
}



/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string num, db_num;
    cin >> num;
    int carry = 0;
    for(int i = num.size() - 1; i >= 0; i--)
    {
        int temp = (num[i] - '0') * 2 + carry;
        carry = temp / 10;
        temp %= 10;
        db_num += to_string(temp);
    }
    if(carry)   db_num += "1";
    string ans_num = db_num;
    reverse(ans_num.begin(), ans_num.end());
    sort(db_num.begin(), db_num.end());
    sort(num.begin(), num.end());
    string ans = num == db_num ? "Yes" : "No";
    cout << ans << endl << ans_num;
}
*/