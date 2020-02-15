#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n, k, course, count;
    string s, name;
    // unordered_map<string, set<int>> student;
    unordered_map<string, vector<int>> student;
    cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> course >> count;
        for(int j = 0; j < count; j++)
        {
            cin >> s;
            // student[s].insert(course);
            student[s].push_back(course);
        }
    }
    for(int i = 0; i < n; i++)
    {
        cin >> name;
        cout << name << " " << student[name].size();
        sort(student[name].begin(), student[name].end());
        for(auto it : student[name])
        {
            cout << " " << it;
        }
        cout << endl;
    }
}