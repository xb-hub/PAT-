#include <iostream>
using namespace std;

char color[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

void tran(int channel)
{
    cout << color[channel / 13] << color[channel % 13];
}

int main()
{
    int red, green, blue;
    cin >> red >> green >> blue;
    cout << "#";
    tran(red);
    tran(green);
    tran(blue);
}