class MyCalendar {
public:
    vector<pair<int,int>>cal;
    int n;
    MyCalendar() {
        n=0;
    }
    
    bool book(int start, int end) {
        // we will try to implement this problem using the start point binary search
        if(n==0){
            n+=1;
            cal.push_back({start,end});
            return true;
        }
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(start==cal[mid].first){
                return false;
            }
            else if(start>cal[mid].first){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        if(h<0){
            if(cal[0].first>=end){
                n+=1;
                cal.insert(cal.begin(),{start,end});
                return true;
            }
            else{
                return false;
            }
        }
        else if(l>=n){
            if(cal[n-1].second<=start){
                n+=1;
                cal.push_back({start,end});
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(cal[l].first>=end&&cal[h].second<=start){
                n+=1;
                cal.insert(cal.begin()+h+1,{start,end});
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
