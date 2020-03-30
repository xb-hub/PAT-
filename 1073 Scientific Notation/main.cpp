#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int index = 0;
    while (s[index] != '.')
    {
        index++;
    }
    int digit_index = index;
    while (s[index] != 'E')
    {
        index++;
    }
    string num = s.substr(1, index - 1);
    int move = stoi(s.substr(index + 2, s.size() - index - 2));
    cout << num << " " << move << endl;
    if(s[0] == '-') cout << "-";
    if(s[index + 1] == '-')
    {
        cout << "0.";
        for(int i = 1; i < move; i++)   cout << "0";
        for(int i = 0; i < num.size(); i++)
        {
            if(num[i] != '.')   cout << num[i];
        }
    }
    else
    {
        if(move >= num.size() - 2)
        {
            for(int i = 0; i < num.size(); i++)
            {
                if(num[i] != '.')   cout << num[i];
            }
            for(int i = 0; i < move - num.size() + digit_index; i++)
            {
                cout << "0";
            }
        }
        else
        {
            for(int i = 0; i < num.size(); i++)
            {
                if(i == move + 2)    cout << ".";
                if(num[i] != '.')   cout << num[i];
            }
        }
        
    }
    
}