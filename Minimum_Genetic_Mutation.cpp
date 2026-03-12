#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st{bank.begin() , bank.end()};
        if(!st.count(endGene))
        {
            return -1;
        }
        int steps=0;
        int size;
        queue<string>q;
        q.push(startGene);
        while(!q.empty())
        {
            size=q.size();
            while(size--)
            {
                string current,temp;
                current=q.front();
                q.pop();
                if(current==endGene)
                {
                    return steps;
                }
                st.erase(current);
                for(int i=0 ; i<8 ; i++)
                {
                    temp=current;
                    temp[i]='A';
                    if(st.count(temp))
                    {
                        q.push(temp);
                    }
                    temp[i]='C';
                    if(st.count(temp))
                    {
                        q.push(temp);
                    }
                    temp[i]='G';
                    if(st.count(temp))
                    {
                        q.push(temp);
                    }
                    temp[i]='T';
                    if(st.count(temp))
                    {
                        q.push(temp);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};


int main()
{
    string start,end;
    vector<string>bank;

    cin>>start>>end;
    for(int i=0 ; i<5 ; i++)
    {
        cin>>bank[i];
    }
    Solution sol;
    int step = sol.minMutation(start , end , bank);
    cout<<step<<endl;
}