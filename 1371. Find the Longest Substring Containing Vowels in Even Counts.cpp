class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int, int> store;
        store[0] = -1; 

        string vowels = "aeiou"; 
        int mask = 0;       
        int res = 0;        

        for (int i = 0; i < s.length(); i++) {

            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j]) {
                    mask = mask ^ (1 << j); 
                    break;
                }
            }

            if (store.find(mask) ==store.end()) {

                store[mask] = i;
            }

            res = max(res, i - store[mask]);
        }
        return res;
    
    }
};
