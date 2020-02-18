#include <iostream>
#include <vector>
using namespace std;

struct Member
{
    int begin, time, vip;
    bool operator< (const Member m) const
    {
        return m.begin > this->begin;
    }
};


int main()
{
    int n, hour, minute, second, k, m;
    cin >> n;
    vector<Member> member(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d %d", &hour, &minute, &second, &member[i].time, &member[i].vip);
        member[i].begin = hour * 60 * 60 + minute * 60 + second;
    }
    cin >> k >> m;
    vector<int> vip(m);
    for(int i = 0; i < m; i++)
    {
        cin >> vip[i];
    }
    sort(member.begin(), member.end());
    // for(auto it : member)
    // {
    //     cout << it.begin << " " << it.time << endl;
    // }
}