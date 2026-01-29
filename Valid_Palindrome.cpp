#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string final="";
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0 ; i<s.length() ; i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
            {
                final+=s[i];
            }
        }        
        int count=0;
        int len = final.length();
        cout<<final<<endl;
        for(int i=0 ; i<len/2 ; i++)
        {
            if(final[i] == final[len-i-1])
            {
                count++;
            }
        }
        cout<<count<<endl;
        if(count==len/2)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    string str;
    getline(cin,str);
    Solution sol;
    bool res = sol.isPalindrome(str);
    cout<<res<<endl;
}