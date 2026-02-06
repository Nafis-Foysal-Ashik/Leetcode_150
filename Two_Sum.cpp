#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i=0 ; i<nums.size() ; i++)
        {
            int x=nums[i];
            for(int j=i+1 ; j<nums.size() ; j++)
            {
                if(target-x==nums[j])
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};

int main()
{
    int n,tar;
    cin>>n>>tar;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>v[i];
    }
    Solution sol;
    vector<int>res= sol.twoSum(v , tar);
    for(int i=0 ; i<2 ; i++)
    {
        cout<<res[i]<<" ";
    }
}