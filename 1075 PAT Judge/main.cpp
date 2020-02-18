#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// struct Submit
// {
//     int user_id, problem_id, score;
//     bool operator< (const Submit s) const
//     {
//         return s.user_id == this->user_id ? (this->problem_id == s.problem_id ? 
//         this->score < s.score : this->problem_id < s.problem_id) : this->user_id < s.user_id ;
//     }
// };
struct Submit
{
    int user_id, total;
    bool operator< (const Submit s) const
    {
        return this->total == s.total ? this->user_id > s.user_id : this->total > s.total;
    }
};


int main()
{
    const int MaxSize = 10001;
    int n, k, m, user_id, problem_id, score;
    cin >> n >> k >> m;
    vector<int> p(k);
    // vector<Submit> info(m);
    vector<vector<int>> info(n + 1, vector<int>(k + 1, -2));
    unordered_map<int, int> info;
    vector<Submit> total(n + 1);
    for(int i = 0; i < k; i++)
    {
        cin >> p[i];
    }
    for(int i = 0; i < m; i++)
    {
        // cin >> info[i].user_id >> info[i].problem_id >> info[i].score;
        cin >> user_id >> problem_id >> score;
        if(score > info[user_id][problem_id])
        {
            info[user_id][problem_id] = score;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            cout << info[i][j] << " ";
        }
        cout << endl;
    }
    // for(int i = 1; i <= n; i++)
    // {
    //     int tmp = 0;
    //     for(int j = 1; j <= k; j++)
    //     {
    //         tmp += info[i][j];
    //     }
    //     total[i] = {i, tmp};
    // }
    // sort(total.begin(), total.end());
    // for(int i = 1; i <= n; i++)
    // {
    //     printf("%d %05d %d", i, total[i].user_id, total[i].total);
    //     for(int j = 1; j <= k; j++)
    //     {
    //         if(info[total[i].user_id][j] == -2)
    //         {
    //             cout << " -";
    //         }
    //         else if(info[total[i].user_id][j] == -1)
    //         {
    //             cout << " 0";
    //         }
    //         else
    //         {
    //             cout << " " << info[total[i].user_id][j];
    //         }
    //     }
    //     cout << endl;
    // }
    // sort(info.begin(), info.end());
    // for(int i = 0; i < m; i++)
    // {
    //     cout << info[i].user_id << " " << info[i].problem_id << " " << info[i].score << endl;
    // }
}