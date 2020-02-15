#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    string s1, s2, s;
    getline(cin, s1);
    getline(cin, s2);
    unordered_map<char, bool> exist;
    for(int i = 0; i < s2.size(); i++)
    {
        exist[s2[i]] = true;
    }
    for(int i = 0; i < s1.size(); i++)
    {
        if(!exist[s1[i]])
        {
            s += s1[i];
        }
    }
    cout << s << endl;
}