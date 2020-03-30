#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int main()
// {
//     int n, count = 0;
//     scanf("%d", &n);
//     vector<int> array(n), index(n);
//     for(int i = 0; i < n; i++)
//     {
//         scanf("%d", &array[i]);
//         index[array[i]] = i;
//     }
//     vector<int> tmp(n);
//     tmp = array;
//     sort(array.begin(), array.end());
//     while (array != tmp)
//     {
//         if(tmp[0] != 0)
//         {
//             swap(tmp[index[0]], tmp[index[index[0]]]);
//             swap(index[tmp[index[0]]], index[0]);
//             count++;
//         }
//         else
//         {
//             for(int i = 1; i < n; i++)
//             {
//                 if(tmp[i] != i)
//                 {
//                     swap(tmp[index[0]], tmp[i]);
//                     swap(index[tmp[i]], index[0]);
//                     break;
//                 }
//             }
//         }
//     }
//     printf("%d", count);
// }

int main()
{
    int n, count = 0;
    scanf("%d", &n);
    vector<int> array(n), index(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
        index[array[i]] = i;
    }
}