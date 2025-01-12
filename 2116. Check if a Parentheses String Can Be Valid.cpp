class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2 != 0) return false; // edge case
        
        int open = 0, close = 0, dyn = 0;
        for(int i=0; i<n; i++){
            if(locked[i] == '0') dyn++;
            else if(s[i] == '(') open++;
            else close++;

            if(dyn+open < close) return false;
        } // check if ')' is overbalanced

        open = close = dyn = 0;
        for(int i=n-1; i>=0; i--){
            if(locked[i] == '0') dyn++;
            else if(s[i] == '(') open++;
            else close++;

            if(dyn+close < open) return false;
        } // check if '(' is overbalanced

        return true;
    }
};
