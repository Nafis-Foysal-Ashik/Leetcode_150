#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        string final_path="";
        for(int i=0 ; i<path.length() ; i++)
        {
            if(path[i]=='/')
            {
                if(final_path.empty() || final_path.back()!='/')
                {
                    final_path+='/';
                }
                while(i<path.length() && path[i]=='/')
                {
                    i++;
                }
                i--;
            }
            else if(path[i]=='.' && i>0 && path[i-1]=='/')
            {
                int start = i;
                while(i<path.length() && path[i]=='.')
                {
                    i++;
                }
                int dot = i-start;
                bool end_check = (i==path.length() || path[i]=='/');
                if(dot==1 && end_check)
                {
                    continue;
                }
                else if(dot==2 && end_check)
                {
                    if(!final_path.empty())
                    {
                        final_path.pop_back();
                    }
                    while (!final_path.empty() && final_path.back()!='/')
                    {
                        final_path.pop_back();
                    }
                    if(final_path.empty())
                    {
                        final_path+='/';
                    }
                }
                else
                {
                    for(int j=0 ; j<dot ; j++)
                    {
                        final_path+='.';
                    }
                }
                i--;
            }
            else
            {
                final_path+=path[i];
            }
        }
        if(final_path.length()>1 && final_path.back()=='/')
        {
            final_path.pop_back();
        }
        return final_path;
    }   
};


int main()
{
    string str;
    cin>>str;
    Solution sol;
    string path = sol.simplifyPath(str);
    cout<<path<<endl;
}