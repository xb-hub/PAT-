#include <iostream>
using namespace std;

int main() {
    int k1, k2, exp, count = 0;
    double coe,res[1001]={0};
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        cin >> exp >> coe;
        res[exp] += coe;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        cin >> exp >> coe;
        res[exp] += coe;
    }
    for(int i = 0; i < 1001; i++)
        if(res[i] != 0)
            count++;
    cout << count;
    for(int i = 1000; i >= 0; i--){
        if(res[i] != 0.0){
            printf("%d %.1lf", i, res[i]);
        }
    }
}