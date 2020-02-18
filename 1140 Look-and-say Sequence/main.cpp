#include <iostream>
using namespace std;

int main()
{
    int n;
    string d, ans = "";
    cin >> d >> n;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < d.size(); j++)
        {
            int count = 1;
            while (d[j] == d[j + 1] && j != d.size() - 1)
            {
                count++;
                j++;
            }
            ans += d[j] + to_string(count);
        }
        d = ans;
        ans = "";
    }
    cout << d << endl;
}