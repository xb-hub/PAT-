#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student
{
    string id;
    int score, number, local_rank;
};

bool cmp(Student a, Student b)
{
    return a.score == b.score ? a.id < b.id : a.score > b.score;
}

int main()
{
    int n, k, sum = 0, rank = 1;
    cin >> n;
    vector<Student> ans;
    for(int i = 0; i < n; i++)
    {
        cin >> k;
        sum += k;
        vector<Student> locations(k);
        for(int j = 0; j < k; j++)
        {
            cin >> locations[j].id >> locations[j].score;
            locations[j].number = i + 1;
        }
        sort(locations.begin(), locations.end(), cmp);
        locations[0].local_rank = 1;
        ans.push_back(locations[0]);
        for(int j = 1; j < k; j++)
        {
            locations[j].local_rank = locations[j].score == locations[j - 1].score ? locations[j - 1].local_rank : j + 1;
            ans.push_back(locations[j]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << sum << endl;
    cout << ans[0].id << " " << rank << " " << ans[0].number << " " << ans[0].local_rank << endl;
    for(int i = 1; i < ans.size(); i++)
    {
        if(ans[i].score != ans[i - 1].score)    rank = i + 1;
        cout << ans[i].id << " " << rank << " " << ans[i].number << " " << ans[i].local_rank << endl;
    }
}