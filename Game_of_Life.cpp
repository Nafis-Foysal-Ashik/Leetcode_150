#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
    }
};

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>>board(m , vector<int>(n));
    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin>>board[i][j];
        }
    }
    Solution sol;
    sol.gameOfLife(board);
}