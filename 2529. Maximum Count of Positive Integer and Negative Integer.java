class Solution {
    public int maximumCount(int[] nums) {
        int pos_count = 0;
        int neg_count = 0;
        int n = nums.length;
        for(int i =0;i<n;i++){
            if(nums[i]>0){
                pos_count++;
            }
            else if(nums[i] < 0){
                neg_count++;
            }

        }
        if(pos_count > neg_count){
            return pos_count;
        }
        else{
            return neg_count;
        }

    }
}
