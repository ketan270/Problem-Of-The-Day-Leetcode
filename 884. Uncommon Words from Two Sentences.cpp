class Solution {
public:
    // Helper function to populate the frequency map
    void helpme(unordered_map<string, int>& mymap, string& s1) {
        string temp = "";
        for (int i = 0; i < s1.size(); i++) {
            temp = "";
            // Extract each word
            while (s1[i] != ' ' && i < s1.size()) {
                temp += s1[i];
                i++;
            }
            mymap[temp]++;  // Update word count in the map
        }
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mymap;
        
        // Count frequencies for both sentences
        helpme(mymap, s1);
        helpme(mymap, s2);
        
        vector<string> ans;
        // Collect words that appear exactly once
        for (pair<string, int> check : mymap) {
            if (check.second == 1) {
                ans.push_back(check.first);
            }
        }
        
        return ans;  // Return the list of uncommon words
    }
};
