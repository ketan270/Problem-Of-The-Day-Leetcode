class Solution {
public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    int dch = change + change, ans = 0;
    vector<vector<int>> g(n+1);
    vector<pair<int,int>> vis(n+1,pair<int,int>({INT_MAX, INT_MAX}));
    
    for(auto &e:edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
    
    queue<pair<int,int>>q;
    q.push({0,1});               //time, vertex
    
    while(!q.empty()){
      auto[t, v] = q.front(); q.pop();
      if(v == n)
        if(ans == 0) ans = t;
        else if(t != ans) return t;
      
      if(vis[v].first == t || vis[v].second <= t) continue; 
      vis[v].first == INT_MAX ? vis[v].first = t : vis[v].second = t ;
      
      t % dch >= change ? t += dch - t % dch + time : t += time;
      
      for(auto &x: g[v]) if(vis[x].second == INT_MAX) q.push({t , x});
    }
    
    return -1;
  }
};
