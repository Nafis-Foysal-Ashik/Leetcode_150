#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<int>&vis, vector<int>&recPath,
             vector<vector<int>>&adj, stack<int>&st)
    {
        vis[node] = 1;
        recPath[node] = 1;

        for(int i = 0; i < adj.size(); i++)
        {
            int v = adj[i][0];
            int u = adj[i][1];

            if(u == node)
            {
                if(!vis[v])
                {
                    if(dfs(v, vis, recPath, adj, st))
                        return true;
                }
                else if(recPath[v])
                    return true;
            }
        }

        recPath[node] = 0;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> vis(numCourses,0);
        vector<int> recPath(numCourses,0);
        stack<int> st;

        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, vis, recPath, prerequisites, st))
                    return {};
            }
        }

        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main()
{
    int numCourses = 4;

    vector<vector<int>> adj;
    adj.push_back({1,0});
    adj.push_back({2,0});
    adj.push_back({3,1});
    adj.push_back({3,2});

    Solution sol;

    vector<int> order = sol.findOrder(numCourses, adj);

    if(order.size()==0)
    {
        cout<<"Cycle detected\n";
    }
    else
    {
        for(int x : order)
            cout<<x<<" ";
    }
}