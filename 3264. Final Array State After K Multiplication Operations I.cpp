class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int>ans;
        while(k--){
            int mini=*min_element(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++){
                if(nums[i]==mini){
                    nums[i]=multiplier*mini;
                    break;
                }
            }
        }
        return nums;
        
    }
};
