#include <cmath>
#include <iostream>
int main() {
    int a, b, n = 0;
    int res[7];
    std::cin >> a >> b;
    int sum = a + b;
    if (sum == 0) std::cout << "0";
    if (sum < 0) std::cout << "-";
    int temp = fabs(sum);
    while (temp != 0) {
        res[n] = temp % 10;
        temp /= 10;
        n++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if ((i + 1) % 3 == 0 && i != n - 1) std::cout << ",";
        std::cout << res[i];
    }
}