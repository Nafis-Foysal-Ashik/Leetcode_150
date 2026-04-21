#include<bits/stdc++.h>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    TreeNode* tree_gen(int start , int end , vector<int>nums)
    {
        if(start>end)
        {
            return nullptr;
        }
        int mid=start+(end-start)/2;
        TreeNode* root =new TreeNode(nums[mid]);
        root->left = tree_gen(start , mid-1 , nums);
        root->right = tree_gen(mid+1 , end , nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return tree_gen(0 , nums.size()-1 , nums);
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
    sol.sortedArrayToBST(v);
}