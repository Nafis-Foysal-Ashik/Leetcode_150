#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> count;
    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (count[nums[i]] < 2) {
            nums[k++] = nums[i];
            count[nums[i]]++;
        }
    }
    return k;
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
    int res = sol.removeDuplicates(v);
}