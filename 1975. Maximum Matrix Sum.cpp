class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minimum=100000;
        long long sum=0;
        int n=matrix.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=matrix[i][j];
                if(x<=0){
                    count++;
                    x*=-1;
                    
                }
                minimum=min(minimum,x);
                sum+=x;
            }
        }
        //check if count is odd 
        if(count&1) sum-=2*minimum;
        return sum;
    }
};
