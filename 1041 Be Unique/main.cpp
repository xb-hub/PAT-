#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> count;
    vector<int> num(n);
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        count[num[i]]++;
        // cout << num << endl;
    }
    for(auto it : num)
    {
        if(count[it] == 1)
        {
            cout << it << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}