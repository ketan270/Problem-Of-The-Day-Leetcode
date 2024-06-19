class Solution {
public:
  
    
    bool makeBouq(vector<int>& bloomDay, int mid, int m, int k){
        int count = k; int numBouq = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){
                count--;
            }else{
                count =k;
            }
            if(count==0){
                numBouq++;
                count = k;
            }
        }

        if(numBouq>=m)return true;

        return false;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m *1ll *k * 1ll;
        if(val>bloomDay.size()) return -1;
 
        int maxi = INT_MIN; int mini = INT_MAX;
        for(int i=0; i<bloomDay.size(); i++){
           maxi = max(maxi, bloomDay[i]);
           mini = min(mini, bloomDay[i]);

        }  

        int l = mini; int r = maxi;
         int mid = 0;
        while(l<=r){
             mid = (l+r)/2;

            bool isPossible = makeBouq(bloomDay, mid, m, k);

            if(isPossible){
               r = mid-1;
            }else{
              l = mid+1;
            }
        }

        return l;

    }
};
