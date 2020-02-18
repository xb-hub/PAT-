#include <iostream>
#include <vector>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    sort(array.begin(), array.end(), cmp);
    for(auto it : array)
    {
        cout << it << " ";
    }
}