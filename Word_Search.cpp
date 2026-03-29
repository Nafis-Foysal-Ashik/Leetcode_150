#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool word_check(vector<vector<char>>&board , string word , int indx , int i , int j)
    {
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[indx])
        {
            return false;
        }
        if(indx==word.length()-1)
        {
            return true;
        }
        char temp = board[i][j];
        board[i][j]='#';
        bool res = word_check(board , word , indx+1 , i-1 , j) || word_check(board , word , indx+1 , i+1 , j) || word_check(board , word , indx+1 , i , j-1) || word_check(board , word , indx+1 , i , j+1);
        board[i][j]=temp;

        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0 ; i<board.size() ; i++)
        {
            for(int j=0 ; j<board[0].size() ; j++)
            {
                if(board[i][j]==word[0])
                {
                    if(word_check(board , word , 0 , i , j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    string str;
    vector<vector<char>>board(3 , vector<char>(4));
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            cin>>board[i][j];
        }
    }
    cin>>str;
    Solution sol;
    bool res = sol.exist(board , str);
    if(res)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}