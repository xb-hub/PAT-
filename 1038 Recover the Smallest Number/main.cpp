#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> num(n);
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end(), cmp);
    string ans;
    for(auto it : num)
    {
        ans += it;
    }
    while(ans.front() == '0')
    {
        ans.erase(ans.begin());
    }
    if(ans.size() == 0) cout << 0 << endl;
    else    cout << ans << endl;
}