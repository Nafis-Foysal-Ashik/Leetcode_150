#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>>roma = {
            {"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10},{"XL",40},
            {"L",50},{"XC",90},{"C",100},{"CD",400},{"D",500},{"CM",900},
            {"M",1000}
        };
        string str="";
        for(int i = roma.size()-1 ; i>=0 ; i--)
        {
            string symbol = roma[i].first;
            int val = roma[i].second;

            if(num/val)
            {
                int count = num/val;
                num = num%val;
                while (count--)
                {
                    str+=symbol;
                }
                
            }
        }
        return str;
    }
};


int main()
{
    int num;
    cin>>num;
    Solution sol;
    string str = sol.intToRoman(num);
    cout<<str<<endl;
    return 0;
}