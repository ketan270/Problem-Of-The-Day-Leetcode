class Solution {
private:
    void helper(vector<int> &ans, int curr, int n){
        if(curr > n) return;
        ans.push_back(curr);
        for(int i = 0 ; i <= 9 ; i++){
            if(curr * 10 + i <= n){
                helper(ans, curr * 10 + i, n);
            } else break;
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note:
        // We need to sort all the integers in the Lexicographical order.
        // Algorithm time : O(n) && Space : O(1)
        // What Lexicographical order 
        // So by arraging in lexicographical order do mean that the numbers with the digits at the lower index value should be coming first if the number at that digit is smaller.
        // 10 2
        // 10 2 --> 10, 2
        // aaabcd aaaccederefd
        // 258978 25898
        //                          root
        // 1    2   3   4   5   6   7   8   9
        // 10 11 12
        // 100
        // 1 to 9
        // Retrace and then after retracing 
        vector<int> ans;
        for(int i = 1 ; i <= 9 ; i++){
            helper(ans, i, n);
        }
        // n = 13
        // n = 1
        // n = 10
        // n = 11
        // n = 12
        return ans;
    }
};
