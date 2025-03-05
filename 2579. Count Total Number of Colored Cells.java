class Solution {
    public long coloredCells(int n) {
        long a = 0;
        long b = 4;
        for(int i=1;i<n;i++){
            a+=b;
            b+=4;
        } 
        return a+1;
    }
}

