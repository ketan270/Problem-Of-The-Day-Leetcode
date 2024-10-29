class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxMoves=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            maxMoves=max(maxMoves,f(i,0,m,n,grid,dp));
        }
        return maxMoves;
    }
    int f(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=0,r=0,down=0;
        if(i>0 && j<n-1 && grid[i-1][j+1]>grid[i][j]){
          up=1+f(i-1,j+1,m,n,grid,dp);
        }
        if(j<n-1 && i<m-1 && grid[i+1][j+1]>grid[i][j]){
          down=1+f(i+1,j+1,m,n,grid,dp);
        }
        if(j<n-1 && grid[i][j+1]>grid[i][j]){
          r=1+f(i,j+1,m,n,grid,dp);
        }
        return dp[i][j]=max(up,max(down,r));
    }
};
