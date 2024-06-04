class Solution {
public:
    static int longestPalindrome(string& s) {
        int freq[58]={0}; //'A'=64~'z'=122
        for(char c: s)
            freq[c-'A']++;
        int len=0;
        bool hasOdd=0;
        for(int f: freq){
            if ((f&1)==0) len+=f;
            else{
                len+=(f-1);
                hasOdd=1;
            }
        }
        return len+hasOdd;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
