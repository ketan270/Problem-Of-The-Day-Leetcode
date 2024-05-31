class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& n : nums)
            mp[n]++;
        vector<int> res;
        for (auto& [key, value] : mp)
            if (value == 1)
                res.push_back(key);

        return res;
    }
};
