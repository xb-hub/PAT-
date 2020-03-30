#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> coin(n);
    map<int, int> exist;
    for(int i = 0; i < n; i++)
    {
        cin >> coin[i];
        exist[coin[i]]++;
    }
    bool flag = false;
    for(auto it : exist)
    {
        if(it.first > m / 2)    break;
        // cout << it.first << " " << m - it.first << endl;
        else if(it.first == m - it.first)
        {
            if(exist[it.first] > 1)
            {
                flag = true;
                cout << it.first << " " << it.first << endl;
                break;
            }
        }
        else if(exist[m - it.first])
        {
            flag = true;
            exist[m - it.first]--;
            cout << it.first << " " << m - it.first << endl;
            break;
        }
    }
    if(!flag)
    {
        cout << "No Solution" << endl;
    }
}