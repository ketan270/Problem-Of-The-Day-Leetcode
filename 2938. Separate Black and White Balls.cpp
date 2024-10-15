class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0, count1 = 0;
        for(int i = 0; i< s.size(); i++){
            if( s[i] == '0')ans += count1;
            else count1++;  
        }
        return ans;
    }
};
