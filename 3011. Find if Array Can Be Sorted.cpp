class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int> mp(257, 0);
        int count = 0, temp = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            count = 0, temp = nums[i];
            while(temp > 0)
            {
                if(temp & 1) // equivalent to (temp % 2 == 1)   
                    count += 1;
                temp = temp >> 1; // equivalent to (temp /= 2)  
            }
            mp[nums[i]] = count;
        }
        
        int mini = 0, mini_ind = 0, flag = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            mini = nums[i], mini_ind = i, count = i, flag = 1;
            for(int j = i; j < nums.size(); j++)
            {
                if(mini > nums[j])
                {
                    mini = nums[j];
                    mini_ind = j;
                }
                if(flag && mp[nums[i]] == mp[nums[j]])
                    count = j;
                else
                    flag = 0;
            }

            // Swap karna padega
            if(mini_ind != i)
            {
                if(count < mini_ind)
                    return false;
                else
                {
                    temp = nums[i];
                    nums[i] = nums[mini_ind];
                    nums[mini_ind] = temp;
                }
            }
        }
        return true;
    }
};
