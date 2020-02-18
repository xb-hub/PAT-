#include <iostream>
using namespace std;

long long a1, a2, b1, b2;

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void tran(long long a1, long long b1)
{
    if(a1 * b1 == 0)
    {
        cout << (b1 == 0 ? "Inf" : "0");
        return;
    }
    if((a1 < 0 && b1 > 0) || (a1 > 0 && b1 < 0)) cout << "(-";
    long long tmp1 = abs(a1);   long long tmp2 = abs(b1);
    long long c1 = gcd(tmp1, tmp2);
    tmp1 /= c1;   tmp2 /= c1;
    if(tmp1 >= tmp2)
    {
        if(tmp1 % tmp2 != 0)
        {
            cout << tmp1 / tmp2 << " " << tmp1 % tmp2 << "/" << tmp2;
        }
        else
        {
            cout << tmp1 / tmp2;
        }
    }
    else
    {
        cout << tmp1 << "/" << tmp2;
    }
    if(a1 * b1 < 0) cout << ")";
}

void arithmetic(char s)
{
    switch (s)
    {
    case '+':
        tran(a1, b1);
        cout << " + ";
        tran(a2, b2);
        cout << " = ";
        tran(a1 * b2 + a2 * b1, b1 * b2);
        cout << endl;
        break;
    case '-':
        tran(a1, b1);
        cout << " - ";
        tran(a2, b2);
        cout << " = ";
        tran(a1 * b2 - a2 * b1, b1 * b2);
        cout << endl;
        break;
    case '*':
        tran(a1, b1);
        cout << " * ";
        tran(a2, b2);
        cout << " = ";
        tran(a1 * a2, b1 * b2);
        cout << endl;
        break;
    case '/':
        tran(a1, b1);
        cout << " / ";
        tran(a2, b2);
        cout << " = ";
        tran(a1 * b2, b1 * a2);
        cout << endl;
        break;
    }
}

int main()
{
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    arithmetic('+');
    arithmetic('-');
    arithmetic('*');
    arithmetic('/');
}