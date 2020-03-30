#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int m, n, color, max_ = 0, dominant;
    scanf("%d %d", &m, &n);
    unordered_map<int, int> count;
    for(int i = 0; i < m * n; i++)
    {
        scanf("%d", &color);
        count[color]++;
        if(count[color] > max_)
        {
            dominant = color;
        }
    }
    printf("%d\n", dominant);
}