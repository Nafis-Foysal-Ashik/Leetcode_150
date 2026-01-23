#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int min_price=prices[0];
        int max_profit=0;
        int max_price;
        for(int i=1 ; i<len ; i++)
        {
            int sell_price = prices[i]-min_price;
            if(max_profit<sell_price)
            {
                max_profit=sell_price;
            }
            if(min_price>prices[i])
            {
                min_price=prices[i];
            }
        }
        return max_profit;
    }
};


int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>v[i];
    }
    Solution sol;
    int res = sol.maxProfit(v);
    cout<<res<<endl;
}