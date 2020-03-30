#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int len = 0, left = 0;
    for(int i = 2; i <= sqrt(n) + 1; i++)
    {
        int temp = 1;   int j;
        for(j = i; j < i <= sqrt(n) + 1; j++)
        {
            temp *= j;
            if(n % temp != 0)   break;
        }
        if(j - i > len)
        {
            len = j - i;
            left = i;
        }
    }
    if(left == 0)   printf("1\n%d", n);
    else
    {
        printf("%d\n", len);
        printf("%d", left);
        for(int i = left + 1; i < left + len; i++)
        {
            printf("*%d", i);
        }
    }
    
}