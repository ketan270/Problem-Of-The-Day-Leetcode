class Solution {
public:
    struct robot {
        int pos;
        int health;
        int order;
        char dir;
    };
    static bool cmp(robot a, robot b) {
        return a.pos < b.pos;
    }
    static bool cmp2(robot a, robot b) {
        return a.order < b.order;
    }

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<robot> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].pos = positions[i];
            arr[i].health = healths[i];
            arr[i].dir = directions[i];
            arr[i].order = i+1; 
        }
        sort(arr.begin(), arr.end(), cmp);

        stack<robot> s;
        vector<robot> tmp;

        for (auto i : arr) {
            if (i.dir == 'R') {
                s.push(i);
                continue;
            }
            if (s.empty()) {
                tmp.push_back(i);
                continue;
            }
            while (!s.empty()) {
                robot j = s.top();
                s.pop();

                if (i.health > j.health) 
                    i.health--;
                else {
                    if (i.health < j.health) {
                        j.health--;
                        s.push(j);
                    }
                    i.health = 0;
                    break;
                }
            }
            if (i.health != 0) tmp.push_back(i); 
        }
        
        while (!s.empty()){
            tmp.push_back(s.top());
            s.pop();
        }
        sort(tmp.begin(), tmp.end(), cmp2);

        vector<int> ans;
        for (auto i : tmp) 
            ans.push_back(i.health);
        return ans;
    }
};
