#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long p;
    cin >> n >> p;
    vector<int> array(n);
    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    int max_ = 0, front = 0, behind = 0;
    while (behind != n)
    {
        if(array[front] * p >= array[behind])
        {
            max_++;
            behind++;
        }
        else
        {
            front++;
            behind++;
        }
    }
    cout << max_ << endl;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     int n;
//     long long p;
//     cin >> n >> p;
//     vector<int> array(n);
//     for(int i = 0; i < n; i++)
//     {
//         cin >> array[i];
//     }
//     sort(array.begin(), array.end());
//     int max_ = 1, index = 1;
//     for(int i = 0; i < n; i++)
//     {
//         if(index == n)    break;
//         for(int j = index; j < n; j++)
//         {
//             if(array[j] > array[i] * p)
//             {
//                 index = j;
//                 if(j - i > max_)    max_ = j - i; 
//                 break;
//             }
//         }
//     }
//     cout << max_ << endl;
// }