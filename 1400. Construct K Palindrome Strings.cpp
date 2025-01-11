class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k)
            return false;
        int freq[26] = {};
        for (char c : s)
            freq[c - 'a']++;
        for (int i = 0; i < 26; i++)
            if ((k -= (freq[i] & 1)) < 0)
                return false;
        return true;
    }
};
