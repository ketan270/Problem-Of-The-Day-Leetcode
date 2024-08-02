class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int countZero = 0;
        int ans = 1e9;
        for(int i=0; i<sum; i++){
            if(nums[i] == 0) countZero++;
        }
        ans = min(ans, countZero);
        for(int i=sum; i<2*n-1; i++){
            if(nums[(i-sum)%n] == 0) countZero--;
            if(nums[i%n] == 0) countZero++;
            ans = min(ans, countZero);   
        }
        return ans;
    }
};
