#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentGas = 0;
        int n=gas.size();
        int totalGas=0;
        int totalCost=0;
        int i,j,start;
        for(int i=0 ; i<n ; i++)
        {
            totalGas+=gas[i];
        }
        for(int j=0 ; j<n ; j++)
        {
            totalCost+=cost[j];
        }
        if(totalGas>=totalCost)
        {
            for(i=0 ; i<n ; i++)
            {
                start = i;
                for(j=i ; j<n ; j++)
                {
                    if(gas[i]>=cost[j])
                    {
                        cout<<"x"<<endl;
                        currentGas += gas[i]-cost[j];
                        if(i<4)
                        i++;
                    }
                    else
                    {
                        currentGas=0;
                        j=start;
                        break;
                    }
                }
            }
            return start;
        }
        return -1;
    }
};

int main()
{
    vector<int>gas;
    vector<int>cost;
    int x;
    for(int i=0 ; i<3 ; i++)
    {
        cin>>x;
        gas.push_back(x);
    }
    for(int i=0 ; i<3 ; i++)
    {
        cin>>x;
        cost.push_back(x);
    }
    Solution sol;
    int index = sol.canCompleteCircuit(gas , cost);
    cout<<index<<endl;
    return 0;
}