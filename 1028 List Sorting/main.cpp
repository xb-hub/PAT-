#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

struct Student
{
    char id[10], name[10];
    int score;
};

bool cmp_1(Student a, Student b)
{
    return strcmp(a.id, b.id) <= 0;
}

bool cmp_2(Student a, Student b)
{
    return strcmp(a.name, b.name) == 0 ? strcmp(a.id, b.id) <= 0 : strcmp(a.name, b.name) <= 0;
}

bool cmp_3(Student a, Student b)
{
    return a.score == b.score ? strcmp(a.id, b.id) <= 0 : a.score < b.score;
}

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);
    vector<Student> record(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s %d", record[i].id, record[i].name, &record[i].score);
    }
    if(c == 1)
    {
        sort(record.begin(), record.end(), cmp_1);
    }
    if(c == 2)
    {
        sort(record.begin(), record.end(), cmp_2);
    }
    if(c == 3)
    {
        sort(record.begin(), record.end(), cmp_3);
    }
    for(int i = 0; i < n; i++)
    {
        printf("%s %s %d\n",record[i].id, record[i].name, record[i].score);
    }
}