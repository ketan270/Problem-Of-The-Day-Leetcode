class Solution {
public:
    static bool comparator(vector<int>&a, vector<int>&b){
        if(a[0]<b[0]){
            return true;
        }
        if(a[0]>b[0]){
            return false;
        }
        if(a[1]<b[1]){
            return true;
        }
        return false;
    }
    void push(vector<pair<int, int>>& stk, int val, int ind, int* top){
        *top=*top+1;
        stk[*top]={val, ind};
    }
    void pop(vector<pair<int, int>>& stk, int* top){
        *top=*top-1;
    }
    int search(vector<pair<int, int>>& stk, int val, int* top){
        if(val>=stk[0].first){
            return -1;
        }
        int low=*top, high=0;
        while(low>=high){
            int mid=(low-high)/2+high;
            if(stk[mid].first>val){
                high=mid+1;
            }
            else{
                low=mid-1;
            }
        }
        return stk[low].second;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int q=queries.size(), n=heights.size();
        vector<int> ans(q);
        vector<vector<int>> sortedQueries;
        for(int i=0;i<q;i++){
            sortedQueries.push_back({max(queries[i][1], queries[i][0]), min(queries[i][0], queries[i][1]), i});
        }
        sort(sortedQueries.begin(), sortedQueries.end(), comparator);
        vector<pair<int, int>> stk(n);
        int* top=new int(-1);
        int prevRight=-1, prevLeft=-1, prevAns=-1, cur=n-1;
        while(q--){
            int rightInd=sortedQueries[q][0];
            int leftInd=sortedQueries[q][1];
            int ansInd=sortedQueries[q][2];
            if(prevRight==rightInd && prevLeft==leftInd){
                ans[ansInd]=ans[prevAns];
                continue;
            }
            if(heights[leftInd]<heights[rightInd] || leftInd==rightInd){
                ans[ansInd]=rightInd;
            }
            else{
                while(cur!=rightInd){
                    while(*top!=-1 && heights[cur]>=stk[*top].first){
                        pop(stk, top);
                    }
                    if(heights[cur]>heights[rightInd])
                    push(stk, heights[cur], cur, top);
                    cur--;
                }
                if(*top!=-1){
                    int curAns=search(stk, heights[leftInd], top);
                    ans[ansInd]=curAns;
                }   
                else{
                    ans[ansInd]=-1;
                }
            }
            prevRight=rightInd;
            prevLeft=leftInd;
            prevAns=ansInd;
        }
        return ans;
    }
};
