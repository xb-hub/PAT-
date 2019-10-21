#include <iostream>
using namespace std;

class Solution
{
public:
    string compute(string s)
    {
        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            sum += s[i] - '0';
        }
        return to_string(sum);
    }
};

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
    Solution solution;
    string s, sum;
    cin >> s;
    sum = solution.compute(s);
    for(int i = 0; i < sum.size(); i++)
    {
        if(i != 0)  cout << " ";
        cout << num[sum[i] - '0'];
    }
}