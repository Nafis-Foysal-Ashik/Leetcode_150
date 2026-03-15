#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recString(int index ,map<char,string>mp , string digits , vector<string>&ans , string curr)
    {
        if(index==digits.size())
        {
            ans.push_back(curr);
        }
        string letter = mp[digits[index]];

        for(auto it : letter)
        {
            recString(index+1 , mp , digits , ans , curr+it);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string>keypad;
        keypad['2']="abc";
        keypad['3']="def";
        keypad['4']="ghi";
        keypad['5']="jkl";
        keypad['6']="mno";
        keypad['7']="pqrs";
        keypad['8']="tuv";
        keypad['9']="wxyz";
        vector<string>ans;
        if(digits.size()==0)
        {
            return {""};
        }
        recString(0 , keypad , digits , ans , "");
        return ans;
    }
};

int main()
{
    string str;
    cin>>str;
    Solution sol;
    vector<string>res = sol.letterCombinations(str);
    for(int i=0 ; i<res.size() ; i++)
    {
        cout<<res[i]<<" ";
    }
}