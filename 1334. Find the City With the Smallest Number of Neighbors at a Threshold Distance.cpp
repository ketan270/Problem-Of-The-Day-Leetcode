class Solution {
    vector<pair<int, int>>ans;
    vector<pair<int, int>>adj[105];
    
private:
    bool static cmp(pair<int, int>c1, pair<int, int>c2)
    {
        if (c1.first != c2.first)     return c2.first > c1.first;
        return c1.second > c2.second;
    }
    
    void helpme(int src, int val ,int n)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int>distance(n+1, 1e8);
        
        distance[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for (auto x:adj[node])
            {
                int nextNode = x.first;
                int nextDist = x.second;
                
                if (distance[nextNode] > distance[node] + nextDist)
                {
                    distance[nextNode] = distance[node] + nextDist;
                    pq.push({distance[nextNode], nextNode});
                }
            }
        }
        
        int count = 0;
        for (int i=0;i<n;i++)
        {
            if (i != src and val >= distance[i])   count += 1;
        }
        ans.push_back({count, src});
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {        
        for (int i=0;i<edges.size();i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];   
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        for (int i=0;i<n;i++)
        {
            helpme(i, distanceThreshold, n);
        }
        
        sort(ans.begin(), ans.end(), cmp);
        return ans[0].second;
    }
};
