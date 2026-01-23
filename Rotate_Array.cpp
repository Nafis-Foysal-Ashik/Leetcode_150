#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        vector<int>temp;
        for(int i = n - k; i < n; i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i = 0; i < n - k; i++)
        {
            temp.push_back(nums[i]);
        }
        // for(int i=0 ; i<n ; i++)
        // {
        //     cout<<temp[i]<<" ";
        // }
        for(int i = 0; i < n; i++)
        {
            nums[i] = temp[i];
        }
        for(int i = 0; i < n; i++)
        {
            cout<<nums[i]<<" ";
        }
    }
};


int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>v[i];
    }
    Solution sol;
    Solution sol;
    sol.rotate(v, k);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}