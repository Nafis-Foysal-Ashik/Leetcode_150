#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        if (s.length() % 2 == 1)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                {
                    st.push(s[i]);
                }
                else if (s[i] == ')' &&  !st.empty() && st.top()=='(')
                {
                    st.pop();
                }
                else if (s[i] == '}'  && !st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else if (s[i] == ']' && !st.empty() && st.top() == '[' )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string str;
    cin >> str;
    Solution sol;
    bool res = sol.isValid(str);
    if (res)
    {
        cout << "This is a valid parenthesis" << endl;
    }
    else
    {
        cout << "This is not a valid parenthesis" << endl;
    }
}