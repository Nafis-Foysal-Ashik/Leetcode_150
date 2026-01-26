#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
       mp['I']=1;
       mp['V']=5;
       mp['X']=10;
       mp['L']=50;
       mp['C']=100;
       mp['D']=500;
       mp['M']=1000;
       int sum=0;
       for(int i=0; i<s.length() ; i++)
       {
            if(s[i]=='C' && s[i+1]=='M')
            {
                sum+=900;
                i++;
            }
            else if(s[i]=='C' && s[i+1]=='D')
            {
                sum+=400;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='L')
            {
                sum+=40;
                i++;
            }
            else if(s[i]=='X' && s[i+1]=='C')
            {
                sum+=90;
                i++;
            }
            else if(s[i]=='I' && s[i+1]=='V')
            {
                sum+=4;
                i++;
            }
            else if(s[i]=='I' && s[i+1]=='X')
            {
                sum+=9;
                i++;
            }
            else
            {
                sum+=mp[s[i]];
            }
       }
       return sum;
    }
};

int main()
{
    string str;
    cin>>str;
    Solution sol;
    int res = sol.romanToInt(str);
    cout<<res<<endl;
    return 0;
}