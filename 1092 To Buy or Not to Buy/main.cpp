#include <iostream>
#include <map>
using namespace std;

int main()
{
    string shop, user;
    cin >> shop >> user;
    map<char, int> exist;
    bool flag = false;
    int miss_count = 0, extra_count = 0;
    for(int i = 0; i < shop.size(); i++)
    {
        exist[shop[i]]++;
    }
    for(int i = 0; i < user.size(); i++)
    {
        exist[user[i]]--;
    }
    for(map<char, int>::iterator it = exist.begin(); it != exist.end(); it++)
    {
        if(it->second < 0)
        {
            miss_count += abs(it->second);
            flag = true;
        }
        else
        {
            extra_count += it->second;
        }
    }
    if(flag)
    {
        cout << "No " << miss_count << endl;
    }
    else
    {
        cout << "Yes " << extra_count << endl;
    }
    
}