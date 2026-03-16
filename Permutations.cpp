#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void recPermutation(int index , vector<vector<int>>&ans , vector<int>&nums)
    {
        if(index==nums.size())//3
        {
            ans.push_back({nums});//{1,2,3}
        }
        for(int i = index ; i<nums.size() ; i++)
        {
            //i=2 index=2
            swap(nums[i] , nums[index]);//1 2 3
            recPermutation(index+1 , ans , nums);
            swap(nums[i] , nums[index]);//1 2 3
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recPermutation(0 , ans , nums);
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0 ; i<n ; i++)
    {
        v.push_back(i+1);
    }
    Solution sol;
    vector<vector<int>> res = sol.permute(v);
    for(int i=0 ; i<res.size() ; i++)
    {
        for(int j=0 ; j<res[i].size() ; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}