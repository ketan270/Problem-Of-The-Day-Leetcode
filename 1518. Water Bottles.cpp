class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles>=numExchange){
            int newone = numBottles/numExchange;
            int remone = numBottles%numExchange;
            ans+=newone;
            numBottles = newone+remone;
        }
        return ans;
    }
};
