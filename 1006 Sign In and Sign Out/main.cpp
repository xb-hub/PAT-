#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct User
{
    string id;
    string sign_in;
    string sign_out;
};

bool unlock(User a, User b)
{
    return a.sign_in < b.sign_in;
}

bool lock(User a, User b)
{
    return a.sign_out > b.sign_out;
}

int main()
{
    int m;
    cin >> m;
    vector<User> user(m);
    for(int i = 0; i < m; i++)
    {
        cin >> user[i].id >> user[i].sign_in >> user[i].sign_out;
    }
    sort(user.begin(), user.end(), unlock);
    cout << user[0].id << " ";
    sort(user.begin(), user.end(), lock);
    cout << user[0].id;
}