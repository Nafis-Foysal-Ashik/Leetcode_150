#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> trio;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size(); first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int second = first + 1;
            int third = nums.size() - 1;
            while (second < third)
            {
                    sum = nums[first] + nums[second] + nums[third];
                    if (sum == 0)
                    {
                        trio.push_back({nums[first], nums[second], nums[third]});
                        second++;
                        third--;
                        while (second<third && nums[second]==nums[second-1])    
                        {
                            second++;
                        }
                        
                    }
                    else if (sum > 0)
                    {
                        third--;
                    }
                    else
                    {
                        second++;
                    }
            }
        }
        return trio;

        /*
        set<vector<int>>uniqueTriplets;
        for(int i=0 ; i<nums.size() ; i++)
        {
            set<int>s;
            int target=-nums[i];
            for(int j=i+1 ; j<nums.size() ; j++)
            {
                int third = target-nums[j];
                if(s.find(third)!=s.end())
                {
                    vector<int>triple = {nums[i] , nums[j] , third};
                    sort(triple.begin() , triple.end());
                    uniqueTriplets.insert(triple);
                }
                s.insert(nums[j]);

                for(int k=j+1 ; k<nums.size() ; k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int>triplets={nums[i] , nums[j] , nums[k]};
                        sort(triplets.begin() , triplets.end());
                        uniqueTriplets.insert(triplets);
                    }
                }

        }
        vector<vector<int>>ans (uniqueTriplets.begin() , uniqueTriplets.end());
        return ans;
        */
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution sol;
    sol.threeSum(v);
}