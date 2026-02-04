#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len1=ransomNote.length();
        int len2=magazine.length();

        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int j=0;
        for(int i=0 ; i<len2 ; i++)
        {
            if(ransomNote[0]!=magazine[i])
            {
                continue;
            }
            // else if(magazine[len2-1]!=ransomNote[len1-1])
            // {
            //     continue;
            // }
            else
            {
                int j=0;
                while(j!=len1)
                {
                    if(ransomNote[j]==magazine[i])
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        break;
                    }
                }
                if(j==len1)
                return true;
            }
        }
        return false;
    }
};

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    Solution sol;
    bool res = sol.canConstruct(str1,str2);
    if(res)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }
}