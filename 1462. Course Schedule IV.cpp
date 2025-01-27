class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bitset<101>> visited(n);

        for(int i=0;i<n;i++){
            visited[i].set(i);
        }

        vector<vector<int>> radjL(n);

        vector<int> inDegree(n, 0);

        for(auto& e: prerequisites){
            radjL[e[1]].push_back(e[0]);

            inDegree[e[0]]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front(); q.pop();

            for(int next: radjL[curr]){
                inDegree[next]--;

                visited[next] |= visited[curr];

                if(inDegree[next] == 0){
                    q.push(next);
                }
            }
        }

        vector<bool> result;

        for(auto& q: queries){
            if(visited[q[0]].test(q[1]) == 1){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }

        return result;
    }
};
