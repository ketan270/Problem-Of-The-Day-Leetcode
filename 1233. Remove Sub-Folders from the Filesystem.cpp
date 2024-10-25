class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        unordered_map<string, int> mp;
        for (auto it : folder) {
            stringstream ss(it);
            string token;
            bool flag = false;
            string e = "";
            while (getline(ss, token, '/')) {
                e += token;
                e += " ";
                if (mp.find(e) != mp.end()) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ans.push_back(it);
                mp[e]++;
            }
        }
        return ans;
    }
};
