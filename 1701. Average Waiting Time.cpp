class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        int time=customers[0][0];
        for(int i=0;i<customers.size();i++){
            time=max(customers[i][0],time)+customers[i][1];
            ans+=time-customers[i][0];
        }
        return ans/((double)customers.size());
    }
};
