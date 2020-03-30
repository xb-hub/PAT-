#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    int ans = array[0];
    for(int i= 1; i < n; i++)
    {
        ans = (ans + array[i]) / 2;
    }
    cout << ans << endl;
}