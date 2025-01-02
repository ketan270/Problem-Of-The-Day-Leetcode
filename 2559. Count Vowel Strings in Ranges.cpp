class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>arr(1, 0);

        for(int i=0; i<words.size(); i++) {
            int temp = 0;
            int x = words[i].size()-1;
            if ((words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u') 
            && (words[i][x]=='a' || words[i][x]=='e' || words[i][x]=='i' || words[i][x]=='o' || words[i][x]=='u')) {
                temp = 1;
            }
            arr.push_back(arr[i] + temp);
        }
        vector<int> res;
        for(int i=0; i<queries.size(); i++) {
            int num = arr[queries[i][1] + 1] - arr[queries[i][0]];
            res.push_back(num);
        }
        return res;
    }
};
