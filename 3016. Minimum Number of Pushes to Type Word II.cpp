class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
       // 2 - abc
       // 2 - ade
       // 3 - bfg 
       // 2 - 3 Alphabets matched earlier
       // 2 -- 5 Aphabets matched (Incorrect)
       // Things to consider
       // 1, *, 0, # will still have no alphabets mapped to it
       // Number of alphabets that are mapped earlier to a key should remain same.
       // We need to push the characters that are repeated more number of times probably in one go.
       // Example : aaabbbaabb
       // 1 + 1 + 1 + 2 + 2 + 2 + 1 + 1 + 2 + 2
       // 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1
       vector<int> count(26, 0);
       for(auto &ch : word) count[ch - 'a']++;
       sort(count.rbegin(), count.rend());
       // 8 Keys where alphabets can be mapped to
       // 8 * 3 --> 24 letters + 2 letters --> 26 letters
       int start  = 8;
       int ans    = 0;
       int cnt    = 1;  // This count represents the number of times a particular character needs to be pressed.  
       for(auto &ele : count){
            if(start == 0){
                start = 8;
                cnt += 1;
            }
            ans += cnt * ele;
            start--;
       } 
       return ans;
    }
};
