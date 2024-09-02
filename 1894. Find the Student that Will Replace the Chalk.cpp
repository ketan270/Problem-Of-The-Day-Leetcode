class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        int total = 0;
        for(int i=0; i<n; i++) {
            total+=chalk[i];
            if(total>k) return i;
        }


        k = k % total;

        for(int i=0; i<n; i++) {
           if(k<chalk[i]) return i;
           k-=chalk[i];
        }


        return 0;

    }
};
