#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<vector<int>> node(100, vector<int>(2, -1));
vector<int> ans;

void post_order(int root)
{
    if(root != -1)
    {
        post_order(node[root][0]);
        post_order(node[root][1]);
        ans.push_back(root);
    }
}

int main()
{
    cin >> n;
    int root, num;
    string s;
    stack<int> st;
    int tmp;
    for(int i = 0; i < 2 * n; i++)
    {
        cin >> s;
        if(i == 0)
        {
            cin >> root;
            st.push(root);
            tmp = root;
            continue;
        }
        if(s == "Push")
        {
            cin >> num;
            st.push(num);
            if(node[tmp][0] == -1)  node[tmp][0] = st.top();
            else    node[tmp][1] = st.top();
            tmp = num;
        }
        else
        {
            if(!st.empty())
            {
                tmp = st.top();
                st.pop();
            }
        }
    }
    post_order(root);
    if(ans.size() != 0)
    {
        cout << ans[0];
        for(int i = 1; i < ans.size(); i++)
        {
            cout << " " << ans[i];
        }
    }
}