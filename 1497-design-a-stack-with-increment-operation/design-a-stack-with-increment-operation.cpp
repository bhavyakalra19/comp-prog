class CustomStack {
public:
    vector<int> arr;
    int n;
    int j;
    CustomStack(int maxSize) {
        arr.resize(maxSize);
        n = maxSize;
        j = -1;
    }
    
    void push(int x) {
        if(j == n - 1){
            return;
        }
        arr[++j] = x;
    }
    
    int pop() {
        if(j == -1){
            return -1;
        }
        return arr[j--];
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(j+1,k); i++){
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */