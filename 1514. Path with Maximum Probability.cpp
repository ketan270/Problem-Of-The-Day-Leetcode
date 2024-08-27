class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v=edges[i][1]; 
            double wt = succProb[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<double>dist(n,-1);
        dist[start_node] = 1.0;
        priority_queue<pair<double,int>, vector<pair<double,int>>>pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            double dis = it.first; int node = it.second;
            for(auto it : adj[node]){
                double neighdist = it.second; int neighnode = it.first;
                if(dis*neighdist > dist[neighnode]){
                    dist[neighnode] = dis*neighdist;
                    pq.push({dist[neighnode], neighnode});
                }
            }
        }
        return dist[end_node]==-1 ? (double)0 : dist[end_node];
    }
};