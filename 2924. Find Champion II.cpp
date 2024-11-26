class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in(n, 0);
        for(vector<int>& edge:edges){
            in[edge[1]]++;
        }
        int count = 0, ans = -1;
        for(int i = 0; i<n; i++){
            if(in[i] == 0){
                count++;
                ans = i;
            }
        }
        return count > 1 ? -1 : ans;
    }
};
