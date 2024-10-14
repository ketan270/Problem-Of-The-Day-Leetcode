class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long>pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }

        long long score = 0;
        while(k--){
            long long val = pq.top();
            pq.pop();
            score+=val;
            pq.push((val+2)/3);
        }
        return score;
    }
};
