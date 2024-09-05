class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    long long sum = 0;

    for (auto i : rolls) {
        sum += i;
    }

    long long f = rolls.size() + n;
    long long remain_sum = (f * mean) - sum;  
    vector<int> res;
    
   
    if (remain_sum > 6 * n || remain_sum < n) {
        return res; 
    }

    if (remain_sum % n == 0) {
        int ans = remain_sum / n;
        res.assign(n, ans);
    }
  
    else {
        res.assign(n, 1);
        remain_sum -= n;  
        for (int i = 0; i < n && remain_sum > 0; i++) {
            int add = min(static_cast<int>(remain_sum), 6 - res[i]); 
            res[i] += add;
            remain_sum -= add;
        }
    }
    
    return res;
}
};
