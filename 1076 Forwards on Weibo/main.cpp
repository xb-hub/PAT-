#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int MaxSize = 1001;
    int n, l, k, num, user, query;
    cin >> n >> l;
    vector<int> net[MaxSize];
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        for(int j = 0; j < num; j++)
        {
            cin >> user;
            net[i].push_back(user);
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> query;
        
    }
}