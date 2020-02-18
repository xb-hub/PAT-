#include <iostream>
#include <vector>
using namespace std;

struct Rational
{
    long long numerator, denominator;
};

long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

Rational add(Rational r1, Rational r2)
{
    Rational r3;
    long long n = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    long long d = r1.denominator * r2.denominator;
    long long tmp = gcd(n, d);
    r3.numerator = n / tmp;
    r3.denominator = d / tmp;
    return r3;
}

void trans(long long n, long long d)
{
    if((n > 0 && d < 0) || (n < 0 && d > 0))    cout << "-";
    n = abs(n); d = abs(d);
    if(n % d == 0)
    {
        cout << n / d << endl;
        return;
    }
    long long tmp = gcd(n, d);
    n /= tmp;   d/= tmp;
    if((n / d) != 0)
    {
        cout << n / d << " ";
        n %= d;
    }
    cout << n << "/" << d << endl;
    
}

int main()
{
    int n;
    cin >> n;
    vector<Rational> rational(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lld/%lld", &rational[i].numerator, &rational[i].denominator);
    }
    for(int i = 1; i < rational.size(); i++)
    {
        rational[i] = add(rational[i], rational[i - 1]);
    }
    long long num = rational.back().numerator;
    long long den = rational.back().denominator;
    trans(num, den);
}