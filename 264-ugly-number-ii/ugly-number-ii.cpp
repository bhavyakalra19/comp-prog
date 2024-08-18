class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0;
        int b = 0;
        int c = 0;
        vector<int> num;
        num.push_back(1);
        for(int i = 0; i < n; i++){
            int check = min(num[a]*2, min(num[b]*3, num[c]*5));
            if(check == num[a]*2){
                a += 1;
            }
            if(check == num[b]*3){
                b += 1;
            }
            if(check == num[c]*5){
                c += 1;
            }
            num.push_back(check);
        }
        return num[n-1];
    }
};