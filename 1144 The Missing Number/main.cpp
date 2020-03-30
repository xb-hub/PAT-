#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> array(n), exist(1000001, 0);
    // map<int, int> exist;
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
        // exist[array[i]]++;
        if(array[i] > 0)
        {
            exist[array[i]]++;
        }
    }
    int i = 1;
    while (exist[i] != 0)
    {
        i++;
    }
    cout << i << endl;
    return 0;
}