#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        map<int,int>mp;
        for(auto it : nums)
        {
            mp[it]++;
        }
        for(auto &p : mp)
        {
            if(p.second > n/2)
                return p.first;
        }
        return -1;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0 ; i<n  ; i++)
    {
        cin>>v[i];
    }
    Solution sol;
    int res = sol.majorityElement(v);
    cout<<res<<endl;
}