class Solution {
private:
    bool static cmp(pair<int, int>& p1, pair<int, int>& p2) {
        if (p1.first == p2.first)
            return (p1.second > p2.second);
        return (p1.first < p2.first);
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int>mp;
        vector<pair<int, int>>vp;
        vector<int> ans;

        // Storing the nums frequency in mp
        for(auto it: nums) mp[it]++;
        
        // Storing the numbers and their frqs in vp {Frequency, The Number}
        for(auto it:mp)
            vp.push_back({it.second, it.first});

        // Sorting according to (cmp) function
        // increasing order based on the frequency,,,
        // if multiple values have the same frequency, sort them in decreasing order.
        sort(vp.begin(), vp.end(), cmp);

        for(auto it:vp) {
            // while the frequency is more than 1
            while(it.first--)
                ans.push_back(it.second);
        }
        // Upvote if you reached here!
        return ans;
    }
};
