#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currentGas = 0;
        int n=gas.size();
        int totalGas=0;
        int totalCost=0;
        int i,j;
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
                for(j=i ; j<n ; j++)
                {
                    if(gas[i]>=cost[j])
                    {
                        currentGas += gas[i]-cost[j];
                        i++;
                    }
                    else
                    {
                        currentGas=0;
                        j=i;
                        break;
                    }
                }
            }
            return i;
        }
        return -1;
    }
};

int main()
{
    vector<int>gas;
    vector<int>cost;
    int x;
    for(int i=0 ; i<5 ; i++)
    {
        cin>>x;
        gas.push_back(x);
    }
    for(int i=0 ; i<5 ; i++)
    {
        cin>>x;
        cost.push_back(x);
    }
    Solution sol;
    int index = sol.canCompleteCircuit(gas , cost);
    cout<<index<<endl;
    return 0;
}