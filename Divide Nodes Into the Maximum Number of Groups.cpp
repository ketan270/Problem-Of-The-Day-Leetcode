class Solution {
public:


int  maxFromEach(map<int,vector<int>>&adj,int i,vector<int>&maxi,vector<int>&vis)

{

int maxii=maxi[i];
vis[i]=1;

    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            maxii=max(maxii, maxFromEach(adj,it,maxi,vis) );
        }
    }


    return maxii;
}

int bfs(map<int,vector<int>>&adj,int i,int n)
{

    queue<int>qq;
    vector<int>vis(n,0);
    qq.push(i);

vis[i]=1;
int level=1;



    while(qq.size()>0)
    {
        int ss=qq.size();

        while(ss--)
        {
            int nn=qq.front();
            qq.pop();
            for(auto it:adj[nn])
            {

                if(!vis[it])
                {
                    qq.push(it);
                    vis[it]=1;
                }
            }
        }
        level++;
    }
    return level-1;
}
bool isBipartite(vector<int>&col,int node,map<int,vector<int>>&adj,int color)
{

    col[node]=color;


    for( int &neigh: adj[node])
    {
        if(col[neigh]==col[node])
        return false;
        if(col[neigh]==-1)
        {
            if((isBipartite(col,neigh,adj,1-color)) == false)
            return false;
        }
    }
    return true;
}
    int magnificentSets(int n, vector<vector<int>>& edges) {

        map<int,vector<int>>adj;

        for(auto it:edges)
        {
            int u=it[0]-1;
            int v=it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        


vector<int>color(n,-1);
        
        for(int node=0;node<n;node++)
        {
            if(color[node]==-1)
            {
                if((isBipartite(color,node,adj,1))==false)
                return -1;

            }
        }


vector<int>maxi(n,0);

for(int i=0;i<n;i++)
{
    maxi[i]=bfs(adj,i,n);
}

// adding all components max
int ans=0;

vector<int>vis(n,0);
for(int i=0;i<n;i++)
{
    if(!vis[i])
    {
        ans+=maxFromEach(adj,i,maxi,vis);
    }
}
return ans;
    }
};
