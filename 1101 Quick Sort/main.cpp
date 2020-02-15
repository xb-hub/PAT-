#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> array(n), tmp(n), ans;
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    tmp = array;
    sort(tmp.begin(), tmp.end());
    int left_max = 0, num = 0;
    for(int i = 0; i < n; i++)
    {
        num = array[i];
        left_max = max(left_max, num);
        if(tmp[i] == num && left_max == num)
        {
            ans.push_back(num);
        }
    }
    cout << ans.size() << endl;
    if(ans.size() == 0) cout << endl;
    else
    {
        cout << ans[0];
        for(int i = 1; i < ans.size(); i++)
        {
            cout << " " << ans[i];
        }
    }
}