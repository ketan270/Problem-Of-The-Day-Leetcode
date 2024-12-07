class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=(r+l)/2, operations=0;
            for(int i : nums){
                operations += (i-1)/mid;
                if(operations>maxOperations){l=mid+1;break;}
            }
            if(operations<=maxOperations){r=mid;}
        }
        return l;
    }
};
