#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>dup_str=strs;
        for(int i=0 ; i<strs.size() ; i++)
        {
            sort(strs[i].begin() , strs[i].end());
        }
        for(int i=0 ; i<strs.size() ; i++)
        {
            cout<<strs[i]<<" ";
        }
        cout<<endl;
        set<string>s;
        
        vector<vector<string>>result;
        for(int i=0 ; i<strs.size() ; i++)
        {
            if(s.find(strs[i])!=s.end())
            {
                continue;
            }
            else
            {
                vector<string>v;
                v.push_back(dup_str[i]);
                s.insert(strs[i]);
                for(int j=i+1 ; j<strs.size() ; j++)
                {
                    if(strs[i]==strs[j])
                    {
                        v.push_back(dup_str[j]);
                    }
                }
                result.push_back(v);
            }
        }
        return result;
    }   
};

int main()
{
    int n;
    cin>>n;
    vector<string>str(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>str[i];
    }
    Solution sol;
    vector<vector<string>> res = sol.groupAnagrams(str);
}