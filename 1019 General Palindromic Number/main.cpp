#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;
    vector<int> ans;
    while (n > 0)
    {
        ans.push_back(n % b);
        n /= b;
    }
    int left = 0, right = ans.size() - 1;
    bool flag = true;
    while (left < right)
    {
        if(ans[left] != ans[right])
        {
            flag = false;
            break;
        }
        else
        {
            left++;
            right--;
        }
    }
    string result = flag ? "Yes" : "No";
    cout << result << endl;
    for(int i = ans.size() - 1; i >= 0; i--)
    {
        if(i != ans.size() - 1)   cout << " ";
        cout << ans[i];
    }
}