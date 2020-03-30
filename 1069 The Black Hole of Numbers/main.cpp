#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int ans;
    cin >> s;
    s.insert(0, 4 - s.length(), '0');
    do
    {
        sort(s.begin(), s.end(), [](char a, char b)->bool {return a > b;});
        string s1 = s;
        sort(s.begin(), s.end());
        string s2 = s;
        ans = stoi(s1) - stoi(s2);
        s = to_string(ans);
        s.insert(0, 4 - s.length(), '0');
        printf("%s - %s = %04d\n", s1.c_str(), s2.c_str(), ans);
    }while (ans != 6174 && ans != 0);
}