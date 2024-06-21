class Solution {
public:
    int helper(int i,bool canUseminutes,vector<int>& customers, vector<int>& grumpy, int minutes,int n,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][canUseminutes]!=-1) return dp[i][canUseminutes];
        int take=0;
        int nottake=0;
        int tookGrumpy=0;
        if(grumpy[i]==0){
            take=customers[i]+helper(i+1,canUseminutes,customers,grumpy,minutes,n,dp);
        }
        nottake=helper(i+1,canUseminutes,customers,grumpy,minutes,n,dp);
        if(canUseminutes){
            int sum=0;
            for(int j=i;j<i+minutes && j<n;j++){
                sum+=customers[j];
            }
            tookGrumpy=sum+helper(i+minutes,0,customers,grumpy,minutes,n,dp);
        }
        
        return dp[i][canUseminutes]=max(take,max(nottake,tookGrumpy));
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return helper(0,1,customers,grumpy,minutes,n,dp);
    }
};
