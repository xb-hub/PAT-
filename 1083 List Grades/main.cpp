#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    string name, id;
    int grade;
    bool operator < (const Student s) const
    {
        return s.grade < this->grade;
    }
};

int main()
{
    int n, grade1, grade2;
    cin >> n;
    vector<Student> record(n);
    for(int i = 0; i < n; i++)
    {
        cin >> record[i].name >> record[i].id >> record[i].grade;
    }
    cin >> grade1 >> grade2;
    sort(record.begin(), record.end());
    bool flag = true;
    for(auto it : record)
    {
        if(it.grade < grade1)   break;
        if(it.grade >= grade1 && it.grade <= grade2)
        {
            flag = false;
            cout << it.name << " " << it.id << endl;
        }
    }
    if(flag)   cout << "NONE" << endl;
}