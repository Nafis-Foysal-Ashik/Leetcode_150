#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recCombination_sum(int index , vector<vector<int>>&res , vector<int>&ans , int target , vector<int>&candidate)
    {
        if(target==0)
        {
            res.push_back(ans);
            return;        }
        if(index==candidate.size())
        {
            return;
        }
        //pick
        if(candidate[index]<=target)
        {
            int baki = target-candidate[index];
            ans.push_back(candidate[index]);
            recCombination_sum(index , res , ans , baki , candidate);
            ans.pop_back();
        }
        //don't pick
        recCombination_sum(index+1 , res , ans , target, candidate);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        recCombination_sum(0 , res , ans , target , candidates);
        return res;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>v[i];
    }
    Solution sol;
    vector<vector<int>> res = sol.combinationSum(v , k);
    for(int i=0 ; i<res.size() ; i++)
    {
        for(int j=0 ; j<res[i].size() ; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}