class Solution {
public:

    int numTeams(vector<int>& rating) {


        int ans=0;
        for(int i=1; i<rating.size()-1; i++){
                    
            int count_small_left=0;
            int count_large_right=0;
            int count_large_left = 0;
            int count_small_right = 0;

            for(int j =0 ; j<i ; j++){
                if(rating[i] < rating[j]) count_small_left++;
                else count_large_left++;
            }

            for(int j=i+1; j < rating.size(); j++){
                if(rating[i] > rating[j]) count_large_right++;
                else count_small_right++;
            }
            ans +=( count_small_left * count_large_right) +( count_large_left * count_small_right);
        }

     

     return ans;
        
    
        
    }

};
