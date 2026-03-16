#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recCombination(int index , vector<int>&ans , vector<vector<int>>&res , vector<int>v , int k)
    {
        if(ans.size()==k)
        {
            res.push_back(ans);
        }
        for(int i=index ; i<v.size() ; i++)
        {
            ans.push_back(v[i]);
            recCombination(i+1 , ans , res , v , k);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        vector<vector<int>>res;
        vector<int>v;
        for(int i=0 ; i<n ; i++)
        {
            v.push_back(i+1);
        }
        recCombination(0 , ans , res , v , k);
        return res;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    Solution sol;
    vector<vector<int>>res = sol.combine(n,k);
    for(int i=0 ; i<res.size() ; i++)
    {
        for(int j=0 ; j<k ; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}