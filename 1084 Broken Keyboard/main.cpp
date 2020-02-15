#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s1, s2;
    vector<char> ans;
    vector<bool> exist(10000);
    cin >> s1 >> s2;
    int index_1 = 0, index_2 = 0;
    while (index_2 != s2.size())
    {
        if(s1[index_1] == s2[index_2])
        {
            index_1++;
            index_2++;
        }
        else
        {
            if(!exist[toupper(s1[index_1])])
            {
                ans.push_back(toupper(s1[index_1]));
                exist[toupper(s1[index_1])] = true;
            }
            index_1++;
        }
    }
    for(int i = index_1; i < s1.size(); i++)
    {
         if(!exist[toupper(s1[i])])
        {
            ans.push_back(toupper(s1[i]));
            exist[toupper(s1[i])] = true;
        }
    }
    for(auto it : ans)
    {
        cout << it;
    }
}