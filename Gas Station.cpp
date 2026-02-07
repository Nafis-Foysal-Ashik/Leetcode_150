#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0;
    int tank = 0, start = 0;

    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];

        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return (totalGas >= totalCost) ? start : -1;
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