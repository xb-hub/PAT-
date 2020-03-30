#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, c, course;
    scanf("%d %d", &n, &k);
    vector<string> record[2501];
    for(int i = 0; i < n; i++)
    {
        string name;
        cin >> name >> c;
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &course);
            record[course].push_back(name);
        }
    }
    for(int i = 1; i <= k; i++)
    {
        sort(record[i].begin(), record[i].end());
        printf("%d %d\n", i, record[i].size());
        for(int j = 0; j < record[i].size(); j++)
        {
            printf("%s\n", record[i][j].c_str());
        }
    }
}