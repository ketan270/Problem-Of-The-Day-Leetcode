class Solution {
public:
    int takeCharacters(string s, int k) {
        int start = 0;
        int n = s.size();
        int end = 0;
        int mina = n;
        vector<int>v(3);
        for(char ch:s){
            v[ch -'a']++;
        }
        if(v[0] < k || v[1] < k || v[2] < k) return -1;
        for(int end =0;end<n;end++){
            v[s[end]-'a']--;
            while(start<=end && (v[0] < k || v[1] < k || v[2] < k)){
                v[s[start++]-'a']++;
            }
            mina = min(mina,n-(end-start+1));
        }
        return mina;
    }
};
