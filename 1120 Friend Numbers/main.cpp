#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    string num;
    cin >> n;
    set<int> ans;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        int tmp = 0;
        for(int i = 0; i < num.size(); i++)
        {
            tmp += (num[i] - '0');
        }
        ans.insert(tmp);
    }
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++)
    {
        if(it != ans.begin())   cout << " ";
        cout << *it;
    }
}