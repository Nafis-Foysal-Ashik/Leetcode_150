#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int>prefix(len , 1);
        vector<int>suffix(len , 1);
        vector<int>res(len , 1);
        for(int i=1 ; i<len ; i++)
        {
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        for(int i=len-2 ; i>=0 ; i--)
        {
            suffix[i]=suffix[i+1]*nums[i+1];
        }
        for(int i=0 ; i<len ; i++)
        {
            res[i]=prefix[i]*suffix[i];
        }
        return res;
    }
};

int main()
{
    int x;
    vector<int>nums;
    for(int i=0 ; i<4 ; i++)
    {
        cin>>x;
        nums.push_back(x);
    }
    Solution sol;
    vector<int>ans = sol.productExceptSelf(nums);
    for(int i=0 ; i<4 ; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
