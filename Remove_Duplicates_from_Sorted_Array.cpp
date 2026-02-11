#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>v=nums;
        while(nums.size()!=0)
        {
            nums.pop_back();
        }
        nums.push_back(v[0]);
        // cout<<nums.size()<<endl;
        // cout<<nums[0];
        for(int i=1 ; i<n ; i++)
        {
            if(nums.back()!=v[i])
            {
                //cout<<i<<" "<<endl;
                nums.push_back(v[i]);
            }
        }
        // if(nums.size()!=0 && nums.back()!=v[n-1])
        // {
        //     nums.push_back(v[n-1]);
        // }
        for(int i=0 ; i<nums.size() ; i++)
        {
            cout<<nums[i]<<" ";
        }
        return nums.size();
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>v[i];
    }
    Solution sol;
    int len = sol.removeDuplicates(v);
    cout<<len<<endl;
}