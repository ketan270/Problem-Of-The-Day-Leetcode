class Solution
{
    vector<int> CheapestFLight(vector<pair<int, int>> adj[], int src)
    {

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(26, INT_MAX);
        dist[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;
                if (cost + edW < dist[adjNode])
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
        return dist;
    }

public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int v = original.size();
        vector<pair<int, int>> adj[26];
        vector<vector<int>> ansv(26, vector<int>(26, INT_MAX));
        
        for (int i = 0; i < v; i++)
        {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }
        int n = source.size();
        long long ans = 0;
        for (int i = 0; i < 26; i++)
        {
            vector<int> temp = CheapestFLight(adj, i);
            ansv[i] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            if (source[i] != target[i])
            {
                if (ansv[source[i] - 'a'][target[i] - 'a'] == INT_MAX)
                {
                    return -1;
                }
                ans += ansv[source[i] - 'a'][target[i] - 'a'];
            }
        }
        return ans;
    }
};
