#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count_p = 0, count_t;
    long long sum = 0;
    count_t = count(s.begin(), s.end(), 'T');
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'P')  count_p++;
        if(s[i] == 'A')  sum = (sum + count_p * count_t % 1000000007) % 1000000007;
        if(s[i] == 'T')  count_t--;
    }
    cout << sum << endl;
}