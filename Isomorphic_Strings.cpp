#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>str1;
        map<char,char>str2;
        for(int i=0 ; i<s.length() ; i++)
        {
            char s1=s[i];
            char s2=t[i];

            if(str1.count(s1))
            {
                if(str1[s1]!=s2)
                return false;
            }
            else
            {
                str1[s1]=s2;
            }
            if(str2.count(s2))
            {
                if(str2[s2]!=s1)
                return false;
            }
            else
            {
                str2[s2]=s1;
            }
        }
        return true;
    }
};


int main()
{
    string str1,str2;
    cin>>str1>>str2;
    Solution sol;
    bool result = sol.isIsomorphic(str1,str2);
    if(result)
    {
        cout<<"Isomorphic"<<endl;
    }
    else
    {
        cout<<"Non-Isomorphic"<<endl;
    }
}