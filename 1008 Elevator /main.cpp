#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int time = 0;
    vector<int> floor(n + 1);
    floor[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> floor[i];
        int temp = floor[i] - floor[i - 1];
        if(temp >= 0)   time += temp * 6;
        else    time += abs(temp) * 4;
    }
    time += 5 * n;
    cout << time;
}