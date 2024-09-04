class Solution {
    int eul(pair<int,int> cur){
        return (cur.first*cur.first + cur.second*cur.second);
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for(vector<int> v:obstacles){
            obs.insert({v[0],v[1]});
        }
        pair<int,int> start = {0,0};
        pair<int,int> dir = {0,1};
        int res = 0;
        for(int com : commands){
            // cout << "cur command : " << com << endl;
            // cout << "cur(outside) : " << start.first << " , " << start.second << endl;
            // cout << "dir(outside) : " << dir.first << " , " << dir.second << endl;
            if(com == -2){
                
                if(dir.second == 1) {
                    dir = {-1,0}; 
                    continue;
                }else if(dir.first == -1){
                    dir = {0,-1}; 
                    continue;
                }else if(dir.second == -1){
                    dir = {1,0};
                    continue;
                }else{
                    dir = {0,1}; 
                    continue;
                }
            }
            if(com == -1){
                if(dir.second == 1){
                    dir = {1,0}; continue;
                }else if(dir.first == 1) {
                    dir = {0,-1}; 
                    continue;
                }else if(dir.second == -1){
                    dir = {-1,0}; 
                    continue;
                }else{
                    dir = {0,1};
                    continue;
                }

            }
            res = max(res,eul(start));
            int k = com;
            int ob_fn = false;
            for(int i=1;i<=com;i++){
                if(dir.second == 1){
                    start.second++;
                    if(obs.find(start) != obs.end()) {
                        start.second--;
                        ob_fn = true;
                        break;
                    }
                    res = max(res,eul(start));
                }
                if(dir.first == -1){
                    start.first--;
                    if(obs.find(start) != obs.end()) {
                        start.first++;
                        ob_fn = true;
                        break;
                    }
                    res = max(res,eul(start));
                }
                if(dir.first == 1){
                    start.first++;
                    if(obs.find(start) != obs.end()) {
                        start.first--;
                        ob_fn = true;
                        break;
                    }
                    res = max(res,eul(start));
                }
                if(dir.second == -1){
                    start.second--;
                    if(obs.find(start) != obs.end()) {
                        start.second++;
                        ob_fn = true;
                        break;
                    }
                    res = max(res,eul(start));
                }
                // cout << "cur : " << start.first << " , " << start.second << endl; 
            }
            if(ob_fn) continue;
        }
        return res;
    }
};
