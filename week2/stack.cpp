#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string cmd;
    int n;
    stack<int> st;
    int data = 0;
    cin >> n;
    for (int i = 0; i < n; i++) // 과연 for와 if/elif가 최선의 방법일까...?
    {
        cin >> cmd;
        if (!cmd.compare("push"))
        {
            cin >> data;
            st.push(data);
        }
        else if (!cmd.compare("pop"))
        {
            int popData = 1;
            if (!st.empty())
            {
                popData = st.top();
                st.pop();
            }
            else
            {
                popData = -1;
            }
            cout << popData << '\n';
        }
        else if (!cmd.compare("top"))
        {
            int popData = 1;
            if (!st.empty())
            {
                popData = st.top();
            }
            else
            {
                popData = -1;
            }
            cout << popData << '\n';
        }
        else if (!cmd.compare("size"))
        {
            int size = st.size();
            cout << size << '\n';
        }
        else if (!cmd.compare("empty"))
        {
            int empty = st.empty();
            cout << empty << '\n';
        }
    }
}