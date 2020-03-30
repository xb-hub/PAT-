#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dowadjust(vector<int> &ans, int low, int high)
{
    int index = 0, left, right, len;
    if(high % 2 == 0)   len = high / 2 - 1;
    else    len = (high - 1) / 2;
    while (index <= len)
    {
        right = 2 * index + 2;  left = 2 * index + 1;
        int tmp = left;
        if(right <= high && ans[right] > ans[left])  tmp = right;
        if(ans[index] <= ans[tmp])   
        {
            swap(ans[index], ans[tmp]);
            index = tmp;
        }
        else
        {
            break;
        }
    }
    // int i = 0, j = i * 2 + 1;
    // while (j <= high)
    // {
    //     if (j + 1 <= high && ans[j] < ans[j + 1])
    //         j = j + 1;
    //     if (ans[i] >= ans[j])
    //         break;
    //     swap(ans[i], ans[j]);
    //     i = j;
    //     j = i * 2 + 1;
    // }
}

int main()
{
    int n;
    cin >> n;
    vector<int> array(n), ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    int i = 1;
    while (i < n && ans[i] >= ans[i - 1])
    {
        i++;
    }
    int tmp = i;
    while (i < n)
    {
        if (ans[i] != array[i])
            break;
        i++;
    }
    if (i == n)
    {
        cout << "Insertion Sort" << endl;
        sort(ans.begin(), ans.begin() + tmp + 1);
    }
    else
    {
        cout << "Heap Sort" << endl;
        int p = n - 1;
        while (p > 1 && ans[p] >= ans[0])
        {
            p--;
        }
        swap(ans[0], ans[p]);
        dowadjust(ans, 0, p - 1);
    }
    for (int j = 0; j < ans.size(); j++)
    {
        if (j != 0)
            cout << " ";
        cout << ans[j];
    }
}