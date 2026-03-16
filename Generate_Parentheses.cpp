#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void recParentheses(vector<string>&ans , string &str , int opening , int closing)
    {
        if(opening==0 && closing==0)
        {
            ans.push_back(str);
            return;
        }
        if(opening>0)
        {
            str.push_back('(');
            recParentheses(ans , str , opening-1 , closing);
            str.pop_back();
        }
        if(closing>0 && opening<closing)
        {
            str.push_back(')');
            recParentheses(ans , str , opening , closing-1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int count_open=n,count_end=n;
        vector<string>ans;
        string str="";
        recParentheses(ans , str , count_open , count_end);
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution sol;
    vector<string> res = sol.generateParenthesis(n);
    for(int i=0 ; i<res.size() ; i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}