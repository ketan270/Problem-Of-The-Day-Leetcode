class Solution {
public:
    int help(vector<int>&nums , int req){
        int count = 0;
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n and nums[j] <= nums[i]+req) j++;
            count+=j-i-1;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int r = nums[n-1]-nums[0];
        int ans = 0;
        while(l<=r){
            int mid = (l+r)/2;
            int val = help(nums,mid);
            if(val<k){
                l=mid+1;
            }else{
                r= mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};
