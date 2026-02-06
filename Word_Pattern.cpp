#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string>mp1;
        map<string,char>mp2;
        int j=1;
        //cout<<s[1]<<endl;
        string str;
        int count=0;
        for(int i=0 ; i<s.length() ; i++)
        {
            if(s[i]==' ')
            {
                count++;
            }
        }
        count++;
        cout<<count<<endl;
        if(count!=pattern.length())
        return false;

        for(int i=0 ; i<pattern.length() ; i++)
        {
            str="";
            while(s[j]!=' ' && j<s.length())
            {
                str+=s[j];
                j++;
            }
            if(mp1.count(pattern[i]))
            {
                if(mp1[pattern[i]]!=str)
                return false;
            }
            mp1[pattern[i]]=str;
            if(mp2.count(str))
            {
                if(mp2[str]!=pattern[i])
                return false;
            }
            mp2[str]=pattern[i];
            j++;
        }
        return true;
    }
};

int main()
{
    string str1,str2;
    cin>>str1;
    getline(cin,str2);
    Solution sol;
    bool res = sol.wordPattern(str1,str2);
    if(res)
    {
        cout<<"Pattern Matched"<<endl;
    }
    else
    {
        cout<<"Pattern does not Matched"<<endl;
    }
}