class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sumK(n - k + 1, 0);
        int curr = accumulate(nums.begin(), nums.begin() + k, 0);

        sumK[0] = curr;
        for (int i = 1; i < sumK.size(); i++) {
            curr += nums[i + k - 1] - nums[i - 1];

            sumK[i] =  curr;
        }

        vector<int> left(sumK.size(), 0);
        int lbest = 0;
        for (int i = 0; i < sumK.size(); i++) {
            if (sumK[i] > sumK[lbest]) {
                lbest = i;
            }
            left[i] = lbest;
        }

        vector<int> right(sumK.size(), 0);
        int rbest = sumK.size() - 1;
        for (int i = sumK.size() - 1; i >= 0; i--) {
            if (sumK[i] >= sumK[rbest]) {
                rbest = i;
            }
            right[i] = rbest;
        }

        int maxi = 0;
        vector<int> ans;
        for (int mid = k; mid < sumK.size() - k; mid++) {
            int l = left[mid - k];
            int r = right[mid + k];
            int total = sumK[l] + sumK[mid] + sumK[r];
            if (total > maxi) {
                
                maxi = total;
                ans = {l, mid, r};
            }
        }

        return ans;
            
    }
};
