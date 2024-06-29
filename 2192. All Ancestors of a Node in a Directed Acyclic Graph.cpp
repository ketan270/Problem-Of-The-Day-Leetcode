class Solution {
private:
    void recur(vector<vector<int>>&adj , int node ,int par, vector<vector<int>>&ans, vector<vector<int>>&dp){
        if(dp[node][par]==1){return;}
        if(node!=par){ans[node].push_back(par);}
        for(auto it : adj[node]){
            recur(adj , it , par , ans,dp);
        }
        dp[node][par]=1;
        return;
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>>ans(n);
        for(int i=0 ; i<n ; i++){
            recur(adj , i , i , ans,dp);
        }
        return ans ;
    }
};
