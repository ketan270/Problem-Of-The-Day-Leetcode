
class Solution {
public:
    int minChanges(string s) {
        
        int n = s.length();

        int i     = 0;
        int flips = 0;

        while(i < n){

            int countZero = 0;
            int countOne = 0;

            for(int count = 1; count <= 2; count++){

                if(s[i] == '0')
                    countZero++;
                else
                    countOne++;
                i++;
            }

            if(countZero == 0){
                continue;
            }
            
            if(countOne == 0){
                continue;
            }

            flips++;
        }

        return flips;

    }
};
