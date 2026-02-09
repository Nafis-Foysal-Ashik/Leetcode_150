#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>updateIntervals;
        int n = intervals.size();
        for(int i=0 ; i<n ; i++)
        {
            int start=intervals[i][0];
            int last=intervals[i][1];
            for(int j=i ; j<n-1 ; j++)
            {
                if(last>=intervals[j+1][0])
                {
                    last = max(last , intervals[j+1][1]);
                    i=j+1;
                }
                else
                {
                    break;
                }
            }
            updateIntervals.push_back({start,last});
        }
        for(int i=0 ; i<updateIntervals.size() ; i++)
        {
            cout<<updateIntervals[i][0]<<" "<<updateIntervals[i][1]<<endl;
        }
        return updateIntervals;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>intervals(n , vector<int>(2));
    for(int i=0 ; i<n ; i++)
    {
        cin>>intervals[i][0]>>intervals[i][1];
    }
    vector<int>newIntervals;
    int x ,y;
    cin>>x>>y;
    newIntervals.push_back(x);
    newIntervals.push_back(y);
    Solution sol;
     vector<vector<int>>updatedIntervals = sol.insert(intervals , newIntervals);  
     for(int i=0 ; i<updatedIntervals.size() ; i++)
     {
        cout<<updatedIntervals[i][0]<<" "<<updatedIntervals[i][1]<<endl;
     }  
}