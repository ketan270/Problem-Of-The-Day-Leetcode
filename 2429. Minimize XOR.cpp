class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int>arr(31,0);
        int num2bit=0,i=0,ans=0;
        while(num2){
            num2bit+=num2&1;
            num2>>=1;
        }
        while(num1){
            arr[i++]=num1&1;
            num1>>=1;
        }
        for(i=arr.size()-1;i>=0;i--){
            if(arr[i] && num2bit){
                arr[i]=-1;
                num2bit--;
            }
        }
        for(i=0;i<arr.size();i++){
         if(num2bit && arr[i]!=-1){
            ans+=pow(2,i);
            num2bit--;
         }
         else if(arr[i]==-1){
          ans+=pow(2,i);
         }
        }
        
        // cout<<num2bit<<" ";
        return ans;
    }
};
