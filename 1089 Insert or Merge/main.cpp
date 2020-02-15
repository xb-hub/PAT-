#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> num(n), st(n);
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> st[i];
    }
    int index = 1;
    while (st[index - 1] < st[index])
    {
        index++;
    }
    int i = 0;
    for(i = index; i < n; i++)
    {
        if(num[i] != st[i]) break;
    }
    if(i == n)
    {
        cout << "Insertion Sort" << endl;
        sort(st.begin(), st.begin() + index + 1);
        cout << st[0];
        for(int i = 1; i < n; i++)
        {
            cout << " " << st[i];
        }
        cout << endl;
    }
    else
    {
        cout << "Merge Sort" << endl;
        int k = 1;
        bool flag = true;
        while (flag)
        {
            if(num == st)   flag = false;
            k *= 2;
            for(int i = 0; i < n / k; i++)
            {
                sort(num.begin() + i * k, num.begin() + (i + 1) * k);
            }
            sort(num.begin() + (n - n % k), num.end());
        }
        cout << num[0];
        for(int i = 1; i < n; i++)
        {
            cout << " " << num[i];
        }
        cout << endl;
    }
    
}