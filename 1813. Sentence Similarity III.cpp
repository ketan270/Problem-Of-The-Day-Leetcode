class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
        istringstream is1(sentence1);
        istringstream is2(sentence2);
        
        vector<string>result1,result2;

        string word;

        while(is1>>word){
            result1.push_back(word);
        }

        while(is2>>word){
            result2.push_back(word);
        }

        int len1=result1.size();
        int len2=result2.size();

        int count=0;

        int m1=min(len1,len2);
        
        for(int i=0;i<m1;i++){
            if(result1[i] != result2[i]) break;
                 count++;
        }
        
        int i=len1-1;
        int j=len2-1;
        while(i>=0 && j>=0){
             if(result1[i] != result2[j]) break;
                count++;
                i--;
                j--;
        }

        if(len1==len2) {
           if(2*len1==count) return true;
        }

        if(len1>len2){
            if(count>=len2) return true;
        }

        if(len1<len2){
            if(count>=len1) return true;
        }

        
        return false;
        }
};
