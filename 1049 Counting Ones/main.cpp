#include <iostream>
using namespace std;

int main()
{
    int n, a = 1, left, mid, right, ans = 0;
    cin >> n;
    while (n / a)
    {
        left = n / (a * 10); mid = n / a % 10;    right = n % a;
        if(mid > 1)    ans += (left + 1) * a;
        else if(mid == 1)  ans += left * a + right + 1;
        else    ans += left * a;
        a *= 10;
    }
    cout << ans << endl;
}