#include <iostream>
using namespace std;

int main()
{
    int g1, s1, k1, g2, s2, k2, carry = 0;;
    int ans_g, ans_s, ans_k;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    ans_k = (k1 + k2) % 29;
    carry = (k1 + k2) / 29;
    ans_s = (s1 + s2 + carry) % 17;
    carry = (s1 + s2 + carry) / 17;
    ans_g = g1 + g2 + carry;
    printf("%d.%d.%d", ans_g, ans_s, ans_k);
}