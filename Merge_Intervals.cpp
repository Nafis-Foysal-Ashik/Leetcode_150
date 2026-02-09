#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;

        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int last  = intervals[i][1];
            for (int j = i; j < n - 1; j++) {
                if (last >= intervals[j + 1][0]) {
                    last = max(last, intervals[j + 1][1]);
                    i = j + 1;
                } else {
                    break;
                }
            }

            v.push_back({start, last});
        }

        for (int i = 0; i < v.size(); i++) {
            cout << v[i][0] << " " << v[i][1] << endl;
        }

        return v;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    Solution sol;
    sol.merge(v);
}
