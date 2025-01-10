class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        // Frequency count vector
        vector<int> max_count(26,0);
        for(int i=0;i<words2.size();i++)
        {
            vector<int> temp(26,0);      // temporary array to count frequency of each string
               for(int j=0;j<words2[i].size();j++)
               {
                char c = words2[i][j];
                temp[c-'a']++;
               }

               // update with the highest frequency
               for(int k=0;k<26;k++){
                max_count[k] = max(max_count[k], temp[k]);}
        }

        // Check each word in words1 if it satisfies the condition of highest frequency
        vector<string> ans;

        for(int i=0;i<words1.size();i++)
        {
            // temproray array to count frequency
            vector<int> temp_count(26,0);

            for(int j=0;j<words1[i].size();j++)
            {
                char c = words1[i][j];
                temp_count[c-'a']++;

            }

            // check if word meets highest frequency
            bool valid = true;
            for(int k=0;k<26;k++)
            {
                if(temp_count[k]<max_count[k])  {
                    valid = false;
                    break;
                }
             
            }
            if(valid) ans.push_back(words1[i]);

        }
      
      return ans;

    }
};
