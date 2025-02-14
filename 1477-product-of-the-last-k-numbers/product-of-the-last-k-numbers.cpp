class ProductOfNumbers {
public:
    vector<int> check;
    int sm;
    int i;
    int j;
    ProductOfNumbers() {
        sm = 1;
        check.resize(40001);
        check[0] = 1;
        i = 0;
        j = 0;
    }
    void add(int num) {
        if(num == 0){
            i = j+1;
            sm = 1;
        }else{
            sm *= num;
        }
        check[++j] = sm;
    }
    
    int getProduct(int k) {
        if(j - k < i) return 0;
        return check[j] / check[j-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */