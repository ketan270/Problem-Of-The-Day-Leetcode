class MaxHeap {
    private:
        vector<int> arr;
        int parentOf(int child) {
            return (child-1)/2;
        }
        void heapifyDownUp(int index) {
            if(index == 0)
                return;
            int parent = parentOf(index);
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                heapifyDownUp(parent);
            }
        }
        bool doesExists(int index) {
            return (index >= 0 && index < arr.size());
        }
        void heapifyUpDown(int index) {
            int lc = 2*index +1;
            int rc = 2*index +2;
            if(doesExists(lc) && doesExists(rc)) {
                if(arr[lc] >= arr[rc] && arr[lc] > arr[index]) {
                    swap(arr[lc], arr[index]);
                    heapifyUpDown(lc);
                } else if(arr[rc] >= arr[lc] && arr[rc] > arr[index]) {
                    swap(arr[rc], arr[index]);
                    heapifyUpDown(rc);
                } else {
                    // no one stands a chance to replace parent
                }
            } else if(doesExists(lc)) {
                if(arr[lc] > arr[index]) {
                    swap(arr[lc], arr[index]);
                    heapifyUpDown(lc);
                }
            } else {
                // no children
            }
        }
    public:
        MaxHeap() {}
        MaxHeap(vector<int>& vec) {
            arr = vector<int>(vec.begin(), vec.end());
            uint n = arr.size();
            for(int i=n/2;i>=0;i--) {
                heapifyUpDown(i);
            }
        }
        void push(int& val) {
            arr.push_back(val);
            heapifyDownUp(arr.size()-1);
        }
        int top() {
            assert(arr.size() != 0);
            return arr[0];
        }
        bool empty() {
            return (arr.size() == 0);
        }
        void pop() {
            if(empty()) {
                return;
            }
            arr[0] = arr[arr.size()-1];
            arr.pop_back();
            heapifyUpDown(0);
        }
};

class Solution {
    using ll = long long;
public:
    ll sqroot(int num) {
        ll start = 1;
        ll end = num;
        int ans = -1;
        while(start <= end) {
            ll mid = (start + end)/2;
            if((mid*mid) > num) {
                end = mid -1;
            } else {
                ans = mid;
                start = mid+1;
            }
        }
        return ans;
    }
    long long pickGifts(vector<int>& gifts, int k) {
        MaxHeap mh(gifts);
        while(!mh.empty() && k--) {
            auto val = mh.top();
            mh.pop();
            int nval = sqroot(val);
            mh.push(nval);
        }
        ll ans = 0;
        while(!mh.empty()) {
            ans+=mh.top();
            mh.pop();
        }
        return ans;
    }
};
