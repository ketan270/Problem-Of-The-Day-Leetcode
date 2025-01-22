 class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isw) {
        int n=isw.size(),m=isw[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        map<pair<int,int>,bool>vis; 
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(isw[i][j]==1)ans[i][j]=0,vis[{i,j}]=1,q.push({i,j}); 
            }
        }
        while(!q.empty()){
            auto[a,b]=q.front();
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for(int i=0;i<4;++i){
                int nr=a+dr[i]; 
                int nc=b+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[{nr,nc}]){
                    ans[nr][nc]=ans[a][b]+1;
                    q.push({nr,nc});
                    vis[{nr,nc}]=1;
                }
            }

        }
        return ans;
    }
};
