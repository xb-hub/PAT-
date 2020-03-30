#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string num;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        int left = stoi(num.substr(0, num.size() / 2));
        int right = stoi(num.substr(num.size() / 2, num.size() / 2));
        // cout << left << " " << right << endl;
        if((left != 0 && right != 0) && stoi(num) % (left * right) == 0)  cout << "Yes" << endl;
        else    cout << "No" << endl;
    }
}