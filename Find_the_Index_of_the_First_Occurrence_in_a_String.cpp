#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() <needle.length() )
        return -1;
        int len1 = haystack.length();
        int len2 = needle.length();
        for(int i=0 ; i<len1 ; i++)
        {
            int j=0;
            while(j<len2 && needle[j]==haystack[i+j] )
            j++;
            if(j==len2)
            return i;
        }
        return -1;

    }

};


int main()
{
    string str1,str2;
    cin>>str1>>str2;
    Solution sol;
    int indx = sol.strStr(str1 , str2);

    cout<<indx<<endl;
    return 0;

}