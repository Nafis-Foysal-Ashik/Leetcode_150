#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buy_sell(int indx, int buy, vector<int>& values, int n,
                 vector<vector<int>>& dp)
    {
        if (indx == n)
            return 0;

        if (dp[indx][buy] != -1)
            return dp[indx][buy];

        int profit = 0;

        if (buy) {
            profit = max(
                -values[indx] + buy_sell(indx + 1, 0, values, n, dp),
                 buy_sell(indx + 1, 1, values, n, dp)
            );
        } else {
            profit = max(
                values[indx] + buy_sell(indx + 1, 1, values, n, dp),
                buy_sell(indx + 1, 0, values, n, dp)
            );
        }

        return dp[indx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return buy_sell(0, 1, prices, n, dp);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    Solution sol;
    cout << sol.maxProfit(v) << endl;
}
