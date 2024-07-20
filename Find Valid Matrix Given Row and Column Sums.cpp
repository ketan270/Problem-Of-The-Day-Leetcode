class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(); int m = colSum.size(); 

        vector<vector<int>> resultantMatrix(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int mini = min(rowSum[i],colSum[j]);
                if(mini<=rowSum[i] && mini<=colSum[j]){
                    resultantMatrix[i][j] = mini;
                    rowSum[i]-=mini;
                    colSum[j]-=mini;
                }
            }
        }

        return resultantMatrix;
        
    }
};
