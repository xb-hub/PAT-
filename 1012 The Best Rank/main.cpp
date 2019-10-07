#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Exam
{
    string id;
    int c, m, e, a;
};

bool cmp_c(Exam a, Exam b)
{
    return a.c > b.c;
}

bool cmp_m(Exam a, Exam b)
{
    return a.m > b.m;
}

bool cmp_e(Exam a, Exam b)
{
    return a.e > b.e;
}

bool cmp_a(Exam b, Exam c)
{
    return b.a > c.a;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Exam> stu(n);
    map<string, bool> exist;
    for(int i = 0; i < n; i++)
    {
        cin >> stu[i].id >> stu[i].c >> stu[i].m >> stu[i].e;
        stu[i].a = (stu[i].c + stu[i].m + stu[i].e) / 3;
        exist[stu[i].id] = true;
    }
    vector<map<string, int>> rank(4);
    sort(stu.begin(), stu.end(), cmp_c);
    for(int i = 0; i < n; i++)
    {
        rank[1][stu[i].id] = i + 1;
        if(stu[i].c == stu[i - 1].c)    rank[1][stu[i].id] = rank[1][stu[i - 1].id];
    }
    sort(stu.begin(), stu.end(), cmp_m);
    for(int i = 0; i < n; i++)
    {
        rank[2][stu[i].id] = i + 1;
        if(stu[i].m == stu[i - 1].m)    rank[2][stu[i].id] = rank[2][stu[i - 1].id];
    }
    sort(stu.begin(), stu.end(), cmp_e);
    for(int i = 0; i < n; i++)
    {
        rank[3][stu[i].id] = i + 1;
        if(stu[i].e == stu[i - 1].e)    rank[3][stu[i].id] = rank[3][stu[i - 1].id];
    }
    sort(stu.begin(), stu.end(), cmp_a);
    for(int i = 0; i < n; i++)
    {
        rank[0][stu[i].id] = i + 1;
        if(stu[i].a == stu[i - 1].a)    rank[0][stu[i].id] = rank[0][stu[i - 1].id];
    }
    string id;
    char kind[4] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++)
    {
        cin >> id;
        if(!exist[id])
        {
            cout << "N/A" << endl;
            continue;
        }
        char min;
        int min_rank = 1000;
        for(int j = 0; j < 4; j++)
        {
            if(rank[j][id] < min_rank)
            {
                min_rank = rank[j][id];
                min = kind[j];
            }
        }
        cout << min_rank << " " << min << endl;
    }
}