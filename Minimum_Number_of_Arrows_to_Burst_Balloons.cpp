#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin() , points.end());
        vector<vector<int>>updateIntervals;
        int n = points.size();
        for(int i=0 ; i<n ; i++)
        {
            int start=points[i][0];
            int last=points[i][1];
            for(int j=i ; j<n-1 ; j++)
            {
                if(last>=points[j+1][0])
                {
                    last = min(last , points[j+1][1]);
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
        return updateIntervals.size();
    }
};

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n , vector<int>(2));
    for(int i=0 ; i<n ; i++)
    {
        cin>>v[i][0]>>v[i][1];
    }
    Solution sol;
    int ballon = sol.findMinArrowShots(v);
    cout<<ballon<<endl;
}