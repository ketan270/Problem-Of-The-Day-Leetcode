class Solution {
public:
    int minimumDeletions(string s) {
      int minDel = 0;
      int bCount = 0;

      for(int i=0; i<s.length(); i++){
        if(s[i]=='b'){
            bCount++;
        }else{
            minDel = min(minDel+1, bCount);
        }
      }
    
    return minDel;
    }
};
