class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> unqNums;
        for (auto num : nums) {
            unqNums.insert(static_cast<long long>(num));
        }
        
        int maxSSLen = 0;
        for (auto num : nums) {
            int currSSLen = 1;
            long long currNum = static_cast<long long>(num);
            while (unqNums.count(currNum * currNum)) {
                currSSLen++;
                currNum = currNum * currNum;
            }
            maxSSLen = max(maxSSLen, currSSLen);
        }
        
        return maxSSLen == 1 ? -1 : maxSSLen;
    }
};
