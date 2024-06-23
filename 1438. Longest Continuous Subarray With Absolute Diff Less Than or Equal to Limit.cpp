class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n  = nums.size();
        int ans = 0 ,s=0;
        priority_queue<pair<int,int>>mx;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mn;
        for(int i  = 0 ;i<n;i++)
        {
            while(!mx.empty()&&mx.top().second<s)
                mx.pop();
            while(!mn.empty()&&mn.top().second <s)
                mn.pop();
            mx.push({nums[i],i});
            mn.push({nums[i],i});
            if((mx.top().first-mn.top().first)<=limit)
                ans = max(ans,(i-s+1));
            else
                s++;
        }
        return ans;
    }
};
