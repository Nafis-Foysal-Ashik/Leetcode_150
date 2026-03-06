#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int row , int col , vector<vector<char>>&board , vector<vector<int>>&vis , vector<int>del_row , vector<int>del_col)
    {
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        for(int i=0 ; i<4 ; i++)
        {
            int new_row = row + del_row[i];
            int new_col = col + del_col[i];
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && board[new_row][new_col]=='O' && vis[new_row][new_col]==0)
            {
                dfs(new_row , new_col , board , vis , del_row , del_col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>del_row={-1,0,1,0};
        vector<int>del_col={0,1,0,-1};
        for(int j=0 ; j<m ; j++)
        {
            if(board[0][j]=='O' && vis[0][j]==0)
            {
                dfs(0 , j , board , vis , del_row , del_col);
            }
            if(board[n-1][j]=='O' && vis[n-1][j]==0)
            {
                dfs(n-1 , j , board , vis , del_row , del_col);
            }
        }
        for(int i=0 ; i<n ; i++)
        {
            if(board[i][0]=='O' && vis[i][0]==0)
            {
                dfs(i , 0 , board , vis , del_row , del_col);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]==0)
            {
                dfs(i , m-1 , board , vis , del_row , del_col);
            }
        }
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(board[i][j]=='O' && vis[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>board(n , vector<char>(m));
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cin>>board[i][j];
        }
    }
    Solution sol;
    sol.solve(board);
}