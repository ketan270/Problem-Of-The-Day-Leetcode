class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> mp;
        int count = 0;
        for( auto i : allowed ){
            mp[i]++;
        } 

        for( auto st : words ){
            bool cons = true;
            for( auto i : st ){
                if( mp.find(i) == mp.end() ){
                    cons = false;
                    break;
                }
            }
            if( cons )
                count++;
        }

        return count;
    }
};
