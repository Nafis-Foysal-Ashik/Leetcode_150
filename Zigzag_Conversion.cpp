#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        string ans = "";
        int cycleLen = 2 * (numRows - 1);

        for (int row = 0; row < numRows; row++) {
            for (int j = row; j < s.length(); j += cycleLen) {
                ans += s[j];

                int diag = j + cycleLen - 2 * row;
                if (row != 0 && row != numRows - 1 && diag < s.length()) {
                    ans += s[diag];
                }
            }
        }
        return ans;
    }
};

int main() {
    string str;
    cin >> str;
    int numRows;
    cin >> numRows;

    Solution sol;
    cout << sol.convert(str, numRows) << endl;
}
