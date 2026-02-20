#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        cout<<tokens.size()<<endl;
        for(int i=0 ; i<tokens.size() ;  i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(tokens[i]=="+")
                {
                    st.push(a+b);
                }
                else if(tokens[i]=="-")
                {
                    st.push(a-b);
                }
                else if(tokens[i]=="*")
                {
                    st.push(a*b);
                }
                else if(tokens[i]=="/")
                {
                    st.push(a/b);
                }
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

int main()
{
    vector<string>str(5);
    for(int i=0 ; i<5 ; i++)
    {
        cin>>str[i];
    }
    Solution sol;
    int res = sol.evalRPN(str);
    cout<<res<<endl;
}