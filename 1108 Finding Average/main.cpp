#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, count_ = 0, temp = 0;
    double sum = 0;
    cin >> n;
    string num;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        bool flag = false;
        string tmp;
        if(num[0] == '-')   tmp = num.substr(1, num.size() - 1);
        else    tmp = num;
        for(int j = 0; j < tmp.size(); j++)
        {
            if(tmp[j] != '.' && !isdigit(tmp[j]))
            {
                flag = true;
                cout << "ERROR: " << num << " is not a legal number" << endl;
                break;
            }
            if(tmp[j] == '.')
            {
                temp++;
                if(tmp.size() - j  - 1 > 2 || temp == 2)
                {
                    flag = true;
                    cout << "ERROR: " << num << " is not a legal number" << endl;
                    break;
                }
            }
        }
        if(!flag && (stod(num) > 1000 || stod(num) < -1000))
        {
            flag = true;
            cout << "ERROR: " << num << " is not a legal number" << endl;
        }
        if(!flag)
        {
            sum += stod(num);
            count_++;
        }
    }
    if(count_ == 0)
    {
        printf("The average of 0 numbers is Undefined");
    }
    else if(count_ == 1)
    {
        printf("The average of 1 number is %.2f", sum);
    }
    else
    {
        printf("The average of %d numbers is %.2f\n", count_, sum / count_);
    }
}