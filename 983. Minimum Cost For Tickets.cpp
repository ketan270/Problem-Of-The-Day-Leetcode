class Solution {
public:
    
    int solve(vector<int>& days, vector<int>& cost,int index){
        //BASE CASE
        if(index>=days.size()){
            return 0;
        }
        // 1Day pass
        int option1=cost[0]+solve(days,cost,index+1);
        
        //7 days pass
        int i;
        for(i=index;i<days.size() &&days[i]<days[index]+7;i++);
        int option2=cost[1]+solve(days,cost,i);
        
        //30 days pass
        for(i=index;i<days.size() &&days[i]<days[index]+30;i++);
        int option3=cost[2]+solve(days,cost,i);
        
        return min(option1,min(option2,option3));
    }
    
    int solveMem(vector<int>& days, vector<int>& cost,int index,vector<int>&dp){
         //BASE CASE
        if(index>=days.size()){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        // 1Day pass
        int option1=cost[0]+solveMem(days,cost,index+1,dp);
        
        //7 days pass
        int i;
        for(i=index;i<days.size() &&days[i]<days[index]+7;i++);
        int option2=cost[1]+solveMem(days,cost,i,dp);
        
        //30 days pass
        for(i=index;i<days.size() &&days[i]<days[index]+30;i++);
        int option3=cost[2]+solveMem(days,cost,i,dp);
        
        //Store in the dp ans return
        dp[index]=min(option1,min(option2,option3));
        return dp[index];
    }
    
    
    
    
    int solveTab(vector<int>& days, vector<int>& cost){
        //creation dp array
        vector<int>dp(days.size()+1,INT_MAX);
        int n=days.size();
        
        //BASE CASE
        dp[n]=0;
        
        for(int k=n-1;k>=0;k--){
             //1 day
           int option1=cost[0]+dp[k+1];
        
           //7 days pass
           int i;
           for(i=k;i<days.size() &&days[i]<days[k]+7;i++);
           int option2=cost[1]+dp[i];
        
           //30 days pass
           for(i=k;i<days.size() &&days[i]<days[k]+30;i++);
           int option3=cost[2]+dp[i];
        
           //Store in the dp ans return
           dp[k]=min(option1,min(option2,option3));
        }
        
        return dp[0];
    }
    
    
    int optimal(vector<int>& days, vector<int>& cost){
        queue<pair<int,int>>month;
        queue<pair<int,int>>week;
        
        int ans=0;
        
       for(int day:days){
           
           //Step 1 : remove expire date from month and week
           while(!month.empty() && month.front().first+30<=day){
               month.pop();
           }
           
           while(!week.empty() && week.front().first+7<=day){
               week.pop();
           }
           
           //Step 2 : add cost of current day
           month.push(make_pair(day,ans+cost[2]));
           week.push(make_pair(day,ans+cost[1]));
           
           //step 3 : update ans
           ans=min(ans+cost[0],min(week.front().second,month.front().second));
           
       }
        
        return ans;
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        // return solve(days,cost,0);
        // vector<int>dp(days.size()+1,-1);
        // return solveMem(days,cost,0,dp);
        
        // return solveTab(days,cost);
        return optimal(days,cost);
    }
};
