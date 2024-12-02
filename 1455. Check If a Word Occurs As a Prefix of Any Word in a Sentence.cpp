class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int idx=1;
        while(ss>>word){
            if(word.substr(0, searchWord.size())==searchWord) return idx;
            ++idx;
        }
        return -1;
    }
};
