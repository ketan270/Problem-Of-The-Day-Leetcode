// Approach-1 : Using Hashmap

class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i : a) mp[i]++;
        for(int i : b){
            if(mp.find(i)!=mp.end() && mp[i]>0){
                ans.push_back(i);
                mp[i]--;
            }
        }

        return ans;

    }
};
