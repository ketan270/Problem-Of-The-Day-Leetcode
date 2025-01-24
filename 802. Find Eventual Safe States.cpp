class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int>out(n,0);
        for (int i = 0; i < n; i++) out[i] = g[i].size();
        queue<int>q;
        for (int i = 0; i < n; i++) {
            if (out[i] == 0) {
                q.push(i);
            }
        }
        vector<vector<int>>g_(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                g_[g[i][j]].push_back(i);
            }
        }
        vector<int>ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto i : g_[node]) {
                out[i]--;
                if (out[i] == 0) {
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
