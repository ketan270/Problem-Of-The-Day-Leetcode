class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<pair<int,pair<bool,int>>> t;
        int maxi1=0,maxi2=0;

        for(auto& event:events){
            int s=event[0],e=event[1],value=event[2];
            t.push_back({s,{true,value}});
            t.push_back({e+1,{false,value}});
        }
        sort(t.begin(),t.end());

        for(auto& val:t){
            int time=val.first;
            bool start=val.second.first;
            int value=val.second.second;

            if(start){
                maxi1=max(maxi1,maxi2+value);
            }
            else{
                maxi2=max(maxi2,value);
            }
        }
        return maxi1;

    }
};
