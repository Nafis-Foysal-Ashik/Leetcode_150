#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin() , nums.end());
        // for(auto it : s)
        // {
        //     cout<<it<<" ";
        // }
        if(nums.size()==0)
        return 0;
        int count=1;
        auto it=s.begin();
        auto prev = it;
        it++;
        int longest=1;
        while(it != s.end())
        {
            if(*it==*prev+1)
            {
                count++;
            }
            else
            {
                count=1;
            }
            prev=it;
            it++;
            longest=max(count,longest);
        }
        return longest;
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
    int res = sol.longestConsecutive(v);
    cout<<res<<endl;
}