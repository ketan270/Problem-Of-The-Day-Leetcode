class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bool flag = false;
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] % 2 != 0) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            if(cnt == 3) {
                flag = true;
                break;
            }
        }
        return flag;
    }
};
