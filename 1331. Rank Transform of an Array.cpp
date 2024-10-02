class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr; // Create a copy of the original array
        unordered_map<int, int> mp;

        // Sort the temporary array
        sort(temp.begin(), temp.end());

        // Remove duplicates
        auto it = unique(temp.begin(), temp.end());
        temp.erase(it, temp.end());

        // Assign ranks to each unique element
        for (int i = 0; i < temp.size(); i++) {
            mp[temp[i]] = i + 1;
        }

        // Replace elements in the original array with their ranks
        vector<int> ans;
        for (auto i : arr) {
            ans.push_back(mp[i]);
        }

        return ans;
    }
};
