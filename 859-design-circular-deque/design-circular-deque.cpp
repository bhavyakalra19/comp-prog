class MyCircularDeque {
public:
    int check[2001];
    int i;
    int j;
    int mx;
    MyCircularDeque(int k) {
        i = 1000;
        j = 1001;
        mx = k;
    }

    bool isFull() {
        return (j - i - 1) == mx;
    }
    
    bool isEmpty() {
        return (i+1) == j;
    }

    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        check[j] = value;
        j += 1;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        check[i] = value;
        i -= 1;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        j -= 1;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        i += 1;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return check[j-1];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return check[i+1];
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */