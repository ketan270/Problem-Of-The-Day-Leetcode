class Solution {
public:
    long long dividePlayers(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;

        int pair_sum = accumulate(begin(arr), end(arr), 0) * 2 / n;

        // Populate the frequency map
        for (auto x : arr) {
            mp[x]++;
        }

        long long ans = 0;

        // For each player, find its complement and calculate the product
        for (auto x : arr) {
            if (mp[x] > 0) {
                // Check if there's a complement
                if (mp[pair_sum - x] > 0) {
                    // Add to the answer (product of the pair)
                    ans += (x * (pair_sum - x));

                    // Decrement both values from the map
                    mp[x]--;
                    mp[pair_sum - x]--;
                } else {
                    return -1; // Invalid pairing
                }
            }
        }
        return ans;
    }
};
