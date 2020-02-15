#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string op;
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        getline(cin, op);
        if(op.size() == 3)
        {
            if(s.empty())
            {
                cout << "Invalid" << endl;
            }
            else
            {
                cout << s.top << endl;
                s.pop();
            }
            
        }
        else if(op.size() == 10)
        {
            if(s.empty())
            {
                cout << "Invalid" << endl;
            }
            else
            {
                
            }
            
        }
        else
        {
            int num = stoi(op.substr(5, op.size() - 5));
            s.push(num);
        }
        
    }
}