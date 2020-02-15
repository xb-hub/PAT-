#include <iostream>
#include <set>
#include <map>
using namespace std;

void query(map<string, set<int>> &book, string &tmp)
{
    if (book.find(tmp) != book.end())
    {
        for (auto it = book[tmp].begin(); it != book[tmp].end(); it++)
        {
            printf("%07d\n", *it);
        }
    }
    else
    {
        printf("Not Found\n");
    }
}

int main()
{
    int n, m, choose, id;
    cin >> n;
    map<string, set<int>> title, author, key, publisher, year;
    string title_, author_, key_, publisher_, year_;
    for (int i = 0; i < n; i++)
    {
        cin >> id;
        getchar();
        getline(cin, title_);
        title[title_].insert(id);
        getline(cin, author_);
        author[author_].insert(id);
        while (cin >> key_)
        {
            key[key_].insert(id);
            char c = getchar();
            if (c == '\n')
                break;
        }
        getline(cin, publisher_);
        publisher[publisher_].insert(id);
        getline(cin, year_);
        year[year_].insert(id);
    }
    cin >> m;
    string s;
    for (int i = 0; i < m; i++)
    {
        scanf("%d: ", &choose);
        printf("%d: ", choose);
        getline(cin, s);
        cout << s << endl;
        if (choose == 1)
        {
            query(title, s);
        }
        else if (choose == 2)
        {
            query(author, s);
        }
        else if (choose == 3)
        {
            query(key, s);
        }
        else if (choose == 4)
        {
            query(publisher, s);
        }
        else if (choose == 5)
        {
            query(year, s);
        }
    }
}