class Solution {
public:
vector<int>parent;
vector<int>rank;
int find(int i){
    if(i == parent[i]) return i;
    return parent[i] = find(parent[i]);  
}

void Union(int i, int j){
    int parenta = find(i);
    int parentb = find(j);
    
    if(parenta == parentb) return; 
    if(rank[parenta] > rank[parentb]){
        parent[parentb] = parenta;
    } else if(rank[parenta] < rank[parentb]){
        parent[parenta] = parentb;
    } else {
        parent[parentb] = parenta;
        rank[parenta]++;
    }
}

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n,0);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    Union(i,j);
                }
            }
        }
        int groups=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) groups++;
        }
        return n-groups;
    }
};
