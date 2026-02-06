#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // map<char,int>mp1;
        // map<char,int>mp2;
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

        if(s.length()!=t.length())
        {
            return false;
        }

        for(int i=0 ; i<s.length() ; i++)
        {
            if(s[i]==t[i])
            {
                continue;;
            }
            else
            {
                return false;
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
    bool res = sol.isAnagram(str1,str2);
    if(res)
    {
        cout<<"Valid Anagram"<<endl;
    }
    else
    {
        cout<<"Not a Valid Anagram"<<endl;
    }
}