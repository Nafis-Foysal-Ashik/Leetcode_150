#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int srow = 0, erow = row - 1;
        int scol = 0, ecol = col - 1;

        vector<int> v;

        while (srow <= erow && scol <= ecol)
        {
            // top row
            for (int i = scol; i <= ecol; i++)
                v.push_back(matrix[srow][i]);

            // right column
            for (int i = srow + 1; i <= erow; i++)
                v.push_back(matrix[i][ecol]);

            // bottom row
            if (srow < erow)
            {
                for (int i = ecol - 1; i >= scol; i--)
                    v.push_back(matrix[erow][i]);
            }

            // left column
            if (scol < ecol)
            {
                for (int i = erow - 1; i > srow; i--)
                    v.push_back(matrix[i][scol]);
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return v;
    }
};



int main()
{
    int row,col;
    cin>>row>>col;
    vector<vector<int>>v(row , vector<int>(col));
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ; j++)
        {
            cin>>v[i][j];
        }
    }
    Solution sol;
    vector<int> res = sol.spiralOrder(v);
    for(int num : res)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}