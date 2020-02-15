#include <iostream>
#include <map>
#include <math.h>
#include <vector>
using namespace std;

bool is_prime(int n)
{
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)  return false;
    }
    return true;
}

int main()
{
    int n, k;
    string id;
    map<string, int> rank;
    map<string, bool> exist;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> id;
        rank[id] = i;
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> id;
        cout << id << ": ";
        if(rank.find(id) == rank.end())
        {
            cout << "Are you kidding?" << endl;
            continue;
        }
        if(exist[id] == true)
        {
            cout << "Checked" << endl;
            continue;
        }
        else
        {
            exist[id] = true;
        }
        if(rank[id] == 1)   cout << "Mystery Award" << endl;
        else if(is_prime(rank[id])) cout << "Minion" << endl;
        else    cout << "Chocolate" << endl;
    }
}