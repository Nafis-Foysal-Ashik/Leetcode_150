#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>ran;
        map<char,int>mag;
        for(auto it : ransomNote)
        {
            ran[it]++;
        }
        for(auto it : magazine)
        {
            mag[it]++;
        }
        for(auto it : ran)
        {
            char ch = it.first;
            int frequency = it.second;
            if(mag[ch]>=frequency)
            {
                continue;
            }
            return false;
        }
        return true;
    }
};

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    Solution sol;
    bool res = sol.canConstruct(str1,str2);
    if(res)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
}