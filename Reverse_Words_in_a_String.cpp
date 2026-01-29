#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string str = "";
        int len = s.length();
        int left = 0, right = len - 1;
        //cout<<right<<endl;
        if (s[left] == ' ')
        {
            while (s[left] == ' ')
            {
                left++;
            }
        }
        if (s[right] == ' ')
        {
            while (s[right] == ' ')
            {
                right--;
            }
        }

        //cout<<left<<" "<<right<<endl;
        for(int i=left ; i<=right ; i++)
        {
            if(s[i]==' ' && s[i+1]==' ')
            continue;
            else
            str+=s[i];
        }
        reverse(str.begin() , str.end());
        string rev_str;
        string ans="";
        cout<<str<<endl;
        for(int i=0 ; i<str.length() ; i++)
        {
            rev_str="";
            while (str[i]!=' ' && i<str.length())
            {
                rev_str+=str[i];
                i++;
            }
            reverse(rev_str.begin() , rev_str.end());
            ans+=rev_str;
            if(i-1 != str.length()-1)
            ans+=" ";
        }
        return ans;
    }
};

int main()
{
    string str;
    getline(cin, str);
    Solution sol;
    string res = sol.reverseWords(str);
    cout << res << endl;
}