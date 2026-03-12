#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool cycleCheck(int start , vector<int>&vis , vector<vector<int>>&adj , vector<int>&recPath)
    {
        //start = 3
        vis[start]=1; //1 1 0 1
        recPath[start]=1; //1 1 0 1
        for(int i=0 ; i<adj.size() ; i++)
        {
            int v = adj[i][0];//3
            int u = adj[i][1];//2

            if(u==start)
            {
                if(!vis[v])
                {
                    if(cycleCheck(v , vis , adj , recPath))
                    {
                        return true;
                    }
                }
                else if(recPath[v])
                {
                    return true;
                }
            }
        }
        recPath[start]=0;//1 1 0 0
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses , 0);//0 0 0 
        vector<int>recPath(numCourses , 0);//0 0 0 0

        for(int i=0 ; i<numCourses ; i++)
        {
            if(vis[i]==0)
            {
                if(cycleCheck(i , vis , prerequisites , recPath))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>>adj;
    adj.push_back({1,0});
    adj.push_back({2,0});
    adj.push_back({3,1});
    adj.push_back({3,2});
    Solution sol;
    bool cycle = sol.canFinish(numCourses , adj);
    if(cycle)
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
}