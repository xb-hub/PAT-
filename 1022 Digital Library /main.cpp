#include <iostream>
#include <vector>
using namespace std;

struct Book
{
    int id, year;
    string title, author, keywords, publisher;
};

void split(string s, string &num, string &value)
{
    num = s[0];
    value = s.substr(3, s.size() - 3);
}

int main()
{
    int n, m;
    cin >> n;
    vector<Book> infor(n);
    for(int i = 0; i < n; i++)
    {
        cin >> infor[i].id >> infor[i].title >> infor[i].author >> infor[i].keywords >> infor[i].publisher >> infor[i].year;
    }
    cin >> m;
    string s;
    for(int i = 0; i < m; i++)
    {
        getline(cin, s);
    }
}