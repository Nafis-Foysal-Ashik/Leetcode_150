#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string longestCommonPrefix(vector<string> str)
    {
        string prefix = str[0];
        
        for(int i=1 ; i<prefix.length() ; i++){
            int j=0;
        while(j<prefix.length() && j<str[i].length() && prefix[j]==str[i][j])
        {
            j++;
        }
    
        prefix = prefix.substr(0,j);}
        return prefix;
    }
};


int main()
{
    vector<string>str(3);
    for(int i=0 ; i<3 ; i++)
    {
        cin>>str[i];
    }   
    Solution sol;
    string res = sol.longestCommonPrefix(str);
    cout<<res<<endl;
}