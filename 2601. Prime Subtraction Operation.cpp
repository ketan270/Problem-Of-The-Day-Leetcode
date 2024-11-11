class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }

    int findPrime(int num, int prev) {
        int p = num-prev-1;

        while (num - p > prev && p>0){
            if(isPrime(p)){
                return p;
            }
            else p--;
        }
        return 0;    
        }

    bool primeSubOperation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = nums.size();
        nums[0] -= findPrime(nums[0], 0);
        bool fl = true;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>=nums[i])
            {
                fl=false;
                break;
            }
        }
        if(fl) return true;
        for (int i = 1; i<n; i++){
            nums[i] -= findPrime(nums[i], nums[i-1]);
            if(nums[i]<=nums[i-1]) return false;
        }
        return true;
    }
};
