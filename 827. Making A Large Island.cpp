class Solution {
public:
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>>&Innerq,vector<vector<int>>&vis,int cnt){
        int ans = 0;    
        while(!Innerq.empty()){
            auto [i,j] = Innerq.front();
            ans += 1;
            Innerq.pop();
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};
            for(int k=0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni < grid.size() && nj >=0 && nj < grid[0].size()){
                    if(grid[ni][nj] && vis[ni][nj] == 0){
                        vis[ni][nj] = cnt;
                        Innerq.push({ni,nj});
                    }
                } 
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&vis,int cnt){
        int ans = 1;
        vis[i][j] = cnt;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for(int k=0;k<4;k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni>=0 && ni < grid.size() && nj >=0 && nj < grid[0].size()){
                if(grid[ni][nj] && vis[ni][nj] == 0){
                    ans += dfs(grid,ni,nj,vis,cnt);
                }
            } 
        }
        return ans;
    }


    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<int>res;
        queue<pair<int,int>>q;
        int maxi = INT_MIN;
        res.push_back(-1);
        int cnt = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && vis[i][j] == 0){
                    int ans = dfs(grid,i,j,vis,cnt);
                    
                    // queue<pair<int,int>>Innerq;
                    // Innerq.push({i,j});
                    // vis[i][j] = cnt;
                    // int ans = bfs(grid,Innerq,vis,cnt);

                    maxi = max(ans,maxi);
                    res.push_back(ans);
                    cnt++;
                }
                else if(grid[i][j] == 0) q.push({i,j});
            }
        }

        // cout << "Vis: " << endl;
        // for(auto i:vis){
        //     for(int j:i){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // cout << "Res: " ;
        // for(int i:res) cout << i << " ";
        // cout << endl;

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            vector<bool>ResVis(cnt+1,0);
            int area = 1;
            int dx[4] = {0,0,1,-1};
            int dy[4] = {1,-1,0,0};
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                area += getValidArea(nx,ny,n,ResVis,res,vis);
            }

            maxi = max(area,maxi);
        }
        return maxi;
    }

    int getValidArea(int nx,int ny,int n,vector<bool>&ResVis,vector<int>&res, vector<vector<int>>&vis){
        int area = 0;
        if(nx >=0 && nx < n && ny >=0 && ny < n){
            int num = vis[nx][ny];
            if(!ResVis[num] && num > 0){
                area = res[num];
                ResVis[num] = true;
            }
        }
        return area;
    }
};
