#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>v(row , vector<int>(col));
        int a=0,b=0;
        for(int i=row-1 ; i>=0 ; i--)
        {
            for(int j=0 ; j<col ; j++)
            {
                v[a%row][b%col]=matrix[i][j];
                a++;
            }
            b++;
        }
        matrix=v;
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0; j<m ; j++)
        {
            cin>>v[i][j];
        }
    }
    Solution sol;
    sol.rotate(v);
}