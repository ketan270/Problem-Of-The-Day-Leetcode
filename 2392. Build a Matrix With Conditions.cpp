class Solution {
public:
    void printvector(vector<int>&v){
        for(auto i:v)cout<<i<<" ";
        cout<<endl;
    }
    bool iscycle(vector<int>adj[],int n){
        vector<int>in(n+1,0);
        for(int i=1;i<=n;i++){
            for(auto it:adj[i])
                in[it]++;
        }
        queue<int>q;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(in[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0)q.push(it);
            }
        }
        return cnt!=n;
    }

    void dfs(int node, vector<int>adj[],stack<int>&st,vector<int>&vis){
        vis[node]=1;
        for(auto i:adj[node]){
            if(vis[i]==0)dfs(i,adj,st,vis);
        }
        st.push(node);
    }
    vector<int> topo(vector<int>adj[],int k){
        stack<int>st;
        vector<int>ans;
        vector<int>vis(k+1,0);
        for(int i=1;i<=k;i++){
            if(vis[i]==0)dfs(i,adj,st,vis);
        }
        while(st.empty()==false){
            ans.push_back(st.top());
            st.pop();
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>ans(k,vector<int>(k,0));
        vector<int>row[k+1];
        vector<int>col[k+1];
        for(auto i:rowConditions){
            row[i[0]].push_back(i[1]);
        }
        for(auto i:colConditions){
            col[i[0]].push_back(i[1]);
        }
        //if cycle return no solution
        if(iscycle(row,k))return {};
        if(iscycle(col,k))return {};
        
        //find order of index
        vector<int> r = topo(row,k);
        vector<int> l = topo(col,k);
        
        //print topo order
        // printvector(r);
        // printvector(l);

        unordered_map<int,int>mp;
        vector<int>vis(k+1,0);
        for(int i=0;i<l.size();i++)
            mp[l[i]] = i;
        
        for(int i=0;i<r.size();i++){
            int temp = r[i];
            vis[r[i]]=1;
            if(mp.find(temp)==mp.end()){
                for(int j=0;j<k;j++)if(ans[i][j]==0){ans[i][j]=temp;break;}
            }
            else{
                ans[i][mp[temp]] = temp;
                mp.erase(temp);
            }
        }
        for(int i=0;i<l.size();i++){
            int temp = l[i];
            if(mp.find(temp)!=mp.end()){
                for(int j=0;j<k;j++){
                    if(vis[mp[temp]]==0 and ans[j][mp[temp]]){
                        ans[j][mp[temp]] = temp;
                        vis[temp]=1;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
