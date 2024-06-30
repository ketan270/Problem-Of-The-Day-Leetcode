class Solution {
public:
int find(int n,vector<int>&par)
{
    if(n==par[n])return n;
    return par[n]=find(par[n],par);
}
void join(int u,int v,vector<int>&size,vector<int>&par)
{
    int pu=find(u,par);
    int pv=find(v,par);
    if(pu==pv)return;
    if(size[pu]>size[pv])
    {
        size[pu]+=size[pv];
        par[pv]=pu;
    }else
    {
        size[pv]+=size[pu];
        par[pu]=pv;
    }
}
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        vector<int> size(n+1,1),size1(n+1,1);
        vector<int> par(n+1,0),par1(n+1,0);
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            par1[i]=i;
        }
        sort(e.rbegin(),e.rend());
        int cnt=0;
        for(auto i:e)
        {
            if(i[0]==3)
            {
                int f=0;
                if(find(i[1],par)!=find(i[2],par))
                {
                    join(i[1],i[2],size,par);
                    f=1;
                }
                if(find(i[1],par1)!=find(i[2],par1))
                {
                    join(i[1],i[2],size1,par1);
                    f=1;
                }

                if(!f)
                {
                    cnt++;
                }
            }else
            if(i[0]==1)
            {
                if(find(i[1],par)!=find(i[2],par))
                {
                    join(i[1],i[2],size,par);
                }else
                {
                    cnt++;
                }
            }else
            {
                if(find(i[1],par1)!=find(i[2],par1))
                {
                    join(i[1],i[2],size1,par1);
                }else
                {
                    cnt++;
                }
            }
        }
        set<int> s,s1;
        for(int i=1;i<=n;i++)
        {
            s.insert(find(i,par));
            s1.insert(find(i,par1));
        }
        if(s.size()!=1||s1.size()!=1)return -1;
        return cnt;
    }
};
