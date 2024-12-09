class Solution {
public:
    void check(vector<int>&nums,vector<pair<int,int>>&False)
    {
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if((nums[i-1]%2)==(nums[i]%2))
                False.push_back({i-1,i});
        }
    }
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<pair<int,int>>False;

        check(nums,False);

        int fs=False.size(),qrySize=queries.size();

        int n=nums.size();
    
        vector<bool>ans(qrySize,true);

       
        for(int i=0;i<queries.size();i++)
        {
            int lo=0,hi=fs-1,mid;

            while(lo<=hi)
            {
                mid=(lo+hi)/2;

                if(False[mid].first<=queries[i][0])
                {
                    lo=mid+1;
                }
                else
                {
                    hi=mid-1;
                }
            }    

            if((lo<fs&&False[lo].first>=queries[i][0]&&False[lo].second<=queries[i][1])
                    || (hi>=0&&False[hi].first>=queries[i][0]&&False[hi].second<=queries[i][1]))
            {
                ans[i]=false;
            }           
            
        }
       
        return ans;
    }
};
