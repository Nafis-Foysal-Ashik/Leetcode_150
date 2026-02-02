#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            ans = max(ans, h * (right - left));

            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return ans;
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
    cout << sol.maxArea(v) << endl;
}
