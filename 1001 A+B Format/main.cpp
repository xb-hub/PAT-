#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int a, b, sum, result[7], i = 0;
    cin >> a >> b;
    sum = a + b;
    if(sum == 0)
    {
        cout << "0";
        return 0;
    }
    if(sum < 0) cout << "-";
    sum = abs(sum);
    while(sum)
    {
        result[i++] = sum % 10;
        sum /= 10;
    }
    int n = i - 1;
    for(i = n; i >= 0; i--)
    {
        if((i + 1) % 3 == 0 && i != n)    cout << ",";
        cout << result[i];
    }
}