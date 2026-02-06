#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int sum;
        set<int> s;
        while (1)
        {
            if (s.find(n) != s.end())
            {
                return false;
            }
            if (n == 1)
                return true;
            s.insert(n);
            sum = 0;
            while (n != 0)
            {
                int x = n % 10;
                x = x * x;
                n /= 10;
                sum += x;
            }
            n = sum;
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    bool res = sol.isHappy(n);
    if (res)
    {
        cout << "The number is a Happyy Number" << endl;
    }
    else
    {
        cout << "The number is not a Happy Number" << endl;
    }
}