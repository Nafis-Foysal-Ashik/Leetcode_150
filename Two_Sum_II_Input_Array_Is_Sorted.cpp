#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();

        int left=0 , right = n-1;
        while(left<right)
        {
            if(target>numbers[left]+numbers[right])
            {
                right--;
            }
            if(target<numbers[left]+numbers[right])
            {
                left++;
            }
        }
        vector<int>v;
        v.push_back(left+1);
        v.push_back(right+1);
        return v;



        // int i,j;
        // for(i = n-1 ; i>=0 ; i--)
        // {
        //     if(numbers[i]>target && numbers[i]!=0 && target!=0 && numbers[0]>0)
        //     {
        //         continue;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        // j=i;
        // //cout<<j<<endl;
        // vector<int>v;
        // for(int p=0 ; p<=j ; p++)
        // {
        //     for(int q=p+1 ; q<=j ; q++)
        //     {
        //         if(numbers[p]+numbers[q] == target)
        //         {
        //             //cout<<p+1<<" "<<q+1<<endl;
        //             v.push_back(p+1);
        //             v.push_back(q+1);
        //             break;
        //         }
        //     }
        // }
        // return v;
    }  
};

int main()
{
    int n,tar;
    cin>>n>>tar;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>v[i];
    }
    Solution sol;
    vector<int>res(2);
    res = sol.twoSum(v , tar);
    for(int i=0 ; i<res.size() ; i++)
    {
        cout<<res[i]<<" ";
    }
}