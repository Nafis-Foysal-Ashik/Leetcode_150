#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs_traversal(int row , int col , vector<vector<int>>&vis , vector<vector<char>>&grid)
    {
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};

        while (!q.empty())
        {
            int old_row = q.front().first;
            int old_col = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
        {
            int new_row = old_row + delrow[i];
            int new_col = old_col + delcol[i];

            if(new_row>=0 && new_row<n &&
               new_col>=0 && new_col<m &&
               grid[new_row][new_col]=='1' &&
               !vis[new_row][new_col])
            {
                vis[new_row][new_col]=1;
                q.push({new_row,new_col});
            }
        }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int row=0 ; row<n ; row++)
        {
            for(int col=0 ; col<m ; col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    bfs_traversal(row , col , vis , grid);
                    count++;
                }
            }
        }
        return count;
    }
};


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n , vector<char>(m));
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cin>>v[i][j];
        }
    }
    Solution sol;
    int island = sol.numIslands(v);
    cout<<island<<endl;
}