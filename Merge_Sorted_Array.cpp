#include<bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=0;
        int right = 0;
        vector<int>v(m+n);
        int index=0;
        while (left<m && right<n)
        {
            if(nums1[left]<=nums2[right])
            {
                v[index]=nums1[left];
                index++;
                left++;
            }
            else
            {
                v[index]=nums2[right];
                index++;
                right++;
            }
        }

        while (left<m)
        {
            v[index]=nums1[left++];
            index++;
        }

        while(right<n)
        {
            v[index]=nums2[right++];
            index++;
        }
        
        for(int i=0 ; i<v.size() ; i++)
        {
            nums1[i]=v[i];
        }
        
    }
};

int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>a(m);
    vector<int>b(n);
    for(int i=0 ; i<m ; i++)
    {
        cin>>a[i];
    }
    for(int i=0 ; i<n ; i++)
    {
        cin>>b[i];
    }
    Solution sol;
    sol.merge(a , m , b , n);
}

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=nums1.size()-1;
        int right = 0 ;
        while(left>=0 && right<n)
        {
            if(nums1[left]>nums2[right])
            {
                int temp = nums1[left];
                nums1[left] = nums2[right];
                nums2[right]=temp;
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());

        // for(int i=nums1.size() ; i<nums2.size()+nums1.size() ; i++)
        // {
        //     nums1[i]=nums2[i-nums1.size()];
        // }

        // for(int i=0 ; i<nums1.size() ; i++)
        // {
        //     cout<<nums1[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0 ; i<nums1.size() ; i++)
        {
            cout<<nums1[i]<<" ";
        }
        cout<<endl;
        for(int i=0 ; i<nums2.size() ; i++)
        {
            cout<<nums2[i]<<" ";
        }
    }
};

int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>a(m);
    vector<int>b(n);
    for(int i=0 ; i<m ; i++)
    {
        cin>>a[i];
    }
    for(int i=0 ; i<n ; i++)
    {
        cin>>b[i];
    }
    Solution sol;
    sol.merge(a , m , b , n);
}