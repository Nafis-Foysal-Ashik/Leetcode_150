#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*
        for(int i=0 ; i<nums.size() ; i++)
        {
            for(int j=i+1 ; j<nums.size() ; j++){
                if(nums[i]==nums[j])
                {
                    if(j-i<=k)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
        */
       map<int,int>mp;
       for(int i=0 ; i<nums.size() ; i++)
       {
            if(mp.find(nums[i])!=mp.end())
            {
                if(abs(i-mp[nums[i]])<=k)
                {
                    return true;
                }
            }
            mp[nums[i]]=i;
       }
       return false;
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
    int k;
    cin>>k;
    Solution sol;
    bool res = sol.containsNearbyDuplicate(v , k);
    if(res)
    {
        cout<<"Contains Duplicate II"<<endl;
    }
    else
    {
        cout<<"Don't Contains Duplicate II"<<endl;
    }
}