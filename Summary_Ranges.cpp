#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<string>str;
        if(n==0)
        return str;

        
        int pointer=0;
        int start = 0;
        int end = start + 1;
        while (end < n)
        {
            if (nums[pointer] + 1 == nums[end])
            {
                pointer++;
                end++;
            }
            else
            {
                if(start!=pointer)
                str.push_back(to_string(nums[start])+"->"+to_string(nums[pointer]));
                else
                str.push_back(to_string(nums[start]));
                start=end;
                pointer=end;
                end++;
            }
        }if(start!=pointer)
                str.push_back(to_string(nums[start])+"->"+to_string(nums[pointer]));
                else
                str.push_back(to_string(nums[start]));
        
        return str;
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
    vector<string> str = sol.summaryRanges(v);
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
}