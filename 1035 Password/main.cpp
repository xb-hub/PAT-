#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account
{
    string account, password;
};


int main()
{
    int n;
    cin >> n;
    Account a;
    vector<Account> ans;
    for(int i = 0; i < n; i++)
    {
        bool flag = false;
        bool exist = false;
        cin >> a.account >> a.password;
        for(int j = 0; j < a.password.size(); j++)
        {
            switch (a.password[j])
            {
            case '1':
                a.password[j] = '@';
                flag = true;
                break;
            
            case '0':
                a.password[j] = '%';
                flag = true;
                break;

            case 'l':
                a.password[j] = 'L';

                flag = true;
                break;
            
            case 'O':
                a.password[j] = 'o';
                flag = true;
                break;

            default:
                break;
            }
        }
        if(flag)
        {
            ans.push_back(a);
        }
    }
    if(ans.size() != 0)
    {
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].account << " " << ans[i].password << endl;
        }
    }
    else if(n != 1)
    {
        cout << "There are " << n << " accounts and no account is modified" << endl;
    }
    else
    {
        cout << "There is 1 account and no account is modified" << endl;
    }
    
    
}