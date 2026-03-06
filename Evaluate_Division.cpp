#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> adj;

        // Build graph
        for(int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1.0 / values[i]});
        }

        // BFS function
        auto bfs = [&](string src, string target) {

            if(adj.find(src) == adj.end() || adj.find(target) == adj.end())
                return -1.0;

            queue<pair<string,double>> q;
            unordered_set<string> vis;

            q.push({src, 1.0});
            vis.insert(src);

            while(!q.empty()) {

                auto [node, weight] = q.front();
                q.pop();

                if(node == target)
                    return weight;

                for(auto &nei : adj[node]) {
                    string next = nei.first;
                    double w = nei.second;

                    if(!vis.count(next)) {
                        q.push({next, weight * w});
                        vis.insert(next);
                    }
                }
            }

            return -1.0;
        };

        vector<double> result;

        for(auto &q : queries) {
            result.push_back(bfs(q[0], q[1]));
        }

        return result;
    }
};


int main() {

    Solution sol;

    vector<vector<string>> equations = {
        {"a","b"},
        {"b","c"}
    };

    vector<double> values = {2.0, 3.0};

    vector<vector<string>> queries = {
        {"a","c"},
        {"b","a"},
        {"a","e"},
        {"a","a"},
        {"x","x"}
    };

    vector<double> result = sol.calcEquation(equations, values, queries);

    for(double ans : result) {
        cout << ans << " ";
    }

    cout << endl;

    return 0;
}