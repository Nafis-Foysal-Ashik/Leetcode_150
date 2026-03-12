#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool topoSort(int node , vector<vector<int>>&adj , vector<int>&vis , stack<int>&s)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(vis[it]==0)
            {
                topoSort(it , adj , vis , s);
            }
        }
        s.push(node);
    }
};

int main()
{
    int n;
    cin>>n;

    vector<int>vis(n+1 , 0);
    vector<vector<int>>adj(n+1);

    adj[0]={};
    adj[1]={};
    adj[2]={3};
    adj[3]={1};
    adj[4]={0,1};
    adj[5]={0,2};
    stack<int>s;

    Solution sol;
    for(int i=0 ; i<n+1 ; i++)
    {
        if(vis[i]==0)
        {
            bool ans = sol.topoSort(i , adj , vis , s);
        }
    }
}