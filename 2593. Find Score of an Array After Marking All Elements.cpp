
class Solution {
public:
    long long findScore(vector<int>& nums) {
        if (nums.empty()) return 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.emplace(nums[i], i);
        }

        vector<int> visit(nums.size(), 0);
        long long ans = 0;

        while (!pq.empty()) {
            auto [value, index] = pq.top();
            pq.pop();

            if (visit[index] == 0) {
                ans += value;
                if (index > 0) visit[index - 1] = 1;
                if (index < nums.size() - 1) visit[index + 1] = 1;
            }
        }

        return ans;
    }
};
