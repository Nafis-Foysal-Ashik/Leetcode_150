#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        //reverse(s.begin() , s.end());
        int i=s.length()-1;
        int count=0;
        while(i>=0 && s[i]==' ')
        {
            i--;
        }
        while(i>=0 && s[i]!=' ')
        {
            //cout<<s[i]<<endl;
            count++;
            i--;
        }
        return count;
    }
};

int main()
{
    string str;
    getline(cin,str);
    Solution sol;
    int res = sol.lengthOfLastWord(str);
    cout<<res<<endl;
    return 0;
}