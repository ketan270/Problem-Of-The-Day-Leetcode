class Solution {
public:
    bool check(vector<int>& nums) {

        int rotatedPos = 0;

        for(int i=0; i<nums.size()-1; i++)
        {
            // position where the array might be rotated
            if(nums[i] > nums[i+1])
            {
                // array is already rotated once, now this is second time : return false
                if(rotatedPos != 0) return false; 
                rotatedPos = nums[i+1];
            }
        }
        
        if(rotatedPos != 0 && nums[nums.size()-1] > nums[0]) return false; 
        return true;
    }
};
