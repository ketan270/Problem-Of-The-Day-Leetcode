class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int targetRemainder = totalSum % p;
        if (targetRemainder == 0) return 0;
        
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = -1;
        
        int minLength = n;
        long long currentSum = 0;
        
        for (int i = 0; i < n; i++) {
            currentSum += nums[i];
            int currentRemainder = currentSum % p;
            
            int complementRemainder = (currentRemainder - targetRemainder + p) % p;
            
            if (prefixSumMap.find(complementRemainder) != prefixSumMap.end()) {
                minLength = min(minLength, i - prefixSumMap[complementRemainder]);
            }
            
            prefixSumMap[currentRemainder] = i;
        }
        
        return minLength < n ? minLength : -1;
    }
};
