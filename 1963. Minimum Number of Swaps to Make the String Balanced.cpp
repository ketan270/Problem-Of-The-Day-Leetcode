class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        for(const char & ch : s){
            if(ch=='[') cnt++;
            else if(cnt) cnt--;
        }
        return (cnt+1)/2;
    }
};
