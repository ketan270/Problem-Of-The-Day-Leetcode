class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int left=1,right=position[n-1];
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            int cnt=1;int prev=0;
            int flag=0;
            for(int i=1;i<n;i++){
                if(position[i]-position[prev]>=mid){
                    cnt++;
                    prev=i;
                }
            }
            if(cnt>=m)flag=1;
            if(flag==1){
                ans=mid;
                left=mid+1;

            }else{
                right=mid-1;
            }
        }
        return ans;        
    }
};
