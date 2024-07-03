class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4)
            return 0;
        sort(nums.begin(), nums.end());

        int a1 = nums[n-1]-nums[3];
        int a2 = nums[n-2]-nums[2];
        int a3 = nums[n-3]-nums[1];
        int a4 = nums[n-4]-nums[0];

        int min1 = min(a1,a2);
        int min2 = min(a3,a4);

        return min(min1,min2);
    }
};
