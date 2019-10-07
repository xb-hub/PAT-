#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    string name, id;
    char gender;
    int grade;
};

bool female_cmp(Student a, Student b)
{
    return a.grade > b.grade;
}

bool male_cmp(Student a, Student b)
{
    return a.grade < b.grade;
}

int main()
{
    int n;
    bool flag = false;
    cin >> n;
    Student stu;
    vector<Student> female, male;
    for(int i = 0; i < n; i++)
    {
        cin >> stu.name >> stu.gender >> stu.id >> stu.grade;
        if(stu.gender == 'F')   female.push_back(stu);
        else    male.push_back(stu);
    }
    sort(female.begin(), female.end(), female_cmp);
    sort(male.begin(), male.end(), male_cmp);
    if(female.size() == 0)
    {
        cout << "Absent" << endl;
        flag = true;
    }
    else    cout << female[0].name << " " << female[0].id << endl;
    if(male.size() == 0)
    {
        cout << "Absent" << endl;
        flag = true;
    }
    else    cout << male[0].name << " " << male[0].id << endl;
    if(!flag)   cout << female[0].grade - male[0].grade << endl;
    else    cout << "NA" << endl;
    return 0;
}