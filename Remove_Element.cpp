#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i,k;
        sort(nums.begin() , nums.end());
        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]==val)
            {
                break;
            }
        }
        // for(int i=0 ; i<nums.size() ; i++)
        // {
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        // cout<<i<<endl;
        for(k=i+1 ; k<nums.size() ; k++)
        {
            if(nums[k]==val)
            {
                // cout<<"k->"<<k<<endl;
                continue;
            }
            else
            {
                break;
            }
        }
        // cout<<k<<endl;
        while (k<nums.size())
        {
            swap(nums[i],nums[k]);
            i++;
            k++;
        }
        int count=0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]!=val)
            {
                count++;
            }
        }
       
        return count;
    }
};

int main()
{
    int n,val;
    cin>>n>>val;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>v[i];
    }
    Solution sol;
    int res = sol.removeElement(v , val);
    cout<<res<<endl;
}