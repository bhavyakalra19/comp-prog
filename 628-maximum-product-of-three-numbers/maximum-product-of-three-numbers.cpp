class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        vector<int> check(3, -1000);
        vector<int> min_check(2, 1000);
        for(auto &a : nums){
            if(a >= check[0] && a != check[2]){
                check[2] = check[1];
                check[1] = check[0];
                check[0] = a;
            }else if(a >= check[1] && a != check[2]){
                check[2] = check[1];
                check[1] = a;
            }else if(a > check[2]){
                check[2] = a;
            }
            if(a <= min_check[0]){
                min_check[1] = min_check[0];
                min_check[0] = a;
            }else if(a < min_check[1]){
                min_check[1] = a;
            }
        }
        return max(check[0] * check[1] * check[2], min_check[0] * min_check[1] * check[0]);
    }
};