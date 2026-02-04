#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> squares[3][3];

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                {
                    continue;
                }
                char val = board[r][c];

                if (rows[r].count(val) ||
                    cols[c].count(val) ||
                    squares[r / 3][c / 3].count(val))
                {
                    return false;
                }
                rows[r].insert(val);
                cols[c].insert(val);
                squares[r / 3][c / 3].insert(val);
            }
        }
        return true;
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}

    };
    cout << obj.isValidSudoku(board) << endl;
}