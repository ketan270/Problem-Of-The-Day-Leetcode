class Solution {
public:
    int passThePillow(int n, int time) {
        time=time%(2*(n-1));
        int k=min(time,(2*(n-1))-time);
        return k+1;
    }
};
