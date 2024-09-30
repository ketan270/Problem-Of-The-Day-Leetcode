class CustomStack {
    vector<int> store;
    int size,capacity;
public:
    CustomStack(int maxSize) {
        size=0,capacity=maxSize;
    }
    
    void push(int x) {
       if(size==capacity) return;
       store.push_back(x);
       size++;
    }
    
    int pop() {
        if(size==0) return -1;
        int res= store[size-1];
        store.pop_back();
        size--;
        return res;
    }
    
    void increment(int k, int val) {
        k= min(k,size);
       for(int i=0;i<k;i++){
        store[i]+=val;
       }
    }
};
