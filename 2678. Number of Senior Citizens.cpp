class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (auto i : details) {
            string age = i.substr(11, 2);
            if (stoi(age) > 60) count++;
        }
        return count;
    }
};
