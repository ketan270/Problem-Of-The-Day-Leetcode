class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1, 0);
        
        // Calculate prefix sums
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        // Initialize result and deque
        int minLen = n + 1;  // Initialize to impossible length
        deque<int> dq;       // Will store indices
        
        for(int i = 0; i <= n; i++) {
            // Remove indices from front whose sum is <= k
            while(!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }
            
            // Remove indices from back whose sum is larger
            while(!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        return minLen == n + 1 ? -1 : minLen;
    }
};
