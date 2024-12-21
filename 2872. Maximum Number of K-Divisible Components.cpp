#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int comp = 0;

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, values, k);
        return comp;
    }

private:
    int dfs(int node, int parent, vector<int>& values, int k) {
        int sum = values[node];

        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                sum += dfs(neighbor, node, values, k);
            }
        }

        if (sum % k == 0) {
            comp++;
            return 0;
        }
        return sum % k;
    }
};
