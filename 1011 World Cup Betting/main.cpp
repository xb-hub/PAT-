#include <iostream>
using namespace std;

int main()
{
    char res[3] = {'W', 'T', 'L'};
    double ans[3] = {0};
    double game;
    for(int i = 0; i < 3; i++)
    {
        int temp = 0;
        for(int j = 0; j < 3; j++)
        {
            cin >> game;
            if(game > ans[i])
            {
                ans[i] = game;
                temp = j;
            }
        }
        cout << res[temp] << " ";
    }
    double result = (ans[0] * ans[1] * ans[2] * 0.65 - 1) * 2;
    printf("%.2f", result);
}