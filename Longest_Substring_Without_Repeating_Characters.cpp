#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len=0;
        for(int i=0 ; i<s.length() ; i++)
        {
            vector<int> hash(255, 0);
            for(int j=i ; j<s.length() ; j++)
            {
                if(hash[s[j]]==1)
                {
                break;
                }
                else
                {
                    len=max(len , j-i+1);
                    hash[s[j]]=1;
                }
            }
        }
        return len;
    }
};

int main()
{
    string str;
    cin>>str;
    Solution sol;
    int len = sol.lengthOfLongestSubstring(str);
    cout<<len<<endl;
}