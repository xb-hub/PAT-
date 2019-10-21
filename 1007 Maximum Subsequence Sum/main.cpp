#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> num(k);
    int temp = 0, sum = 0, left_index = 0, left = 0, right = 0;
    for(int i = 0; i < k; i++)
    {
        cin >> num[i];
        temp += num[i];
        if(temp < 0)
        {
            temp = 0;
            left_index = i + 1;
        }
        else if (temp > sum)
        {
            sum = temp;
            right = i;
            left = left_index;
        }
    }
    // if(sum < 0) sum = 0;
    cout << sum << " " << num[left] << " " << num[right];
}