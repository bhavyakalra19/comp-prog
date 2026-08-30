class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> check(101, 0);
        int n = nums.size();
        int i = 0;
        while(i < n){
            int x = nums[i];
            while(i < n && nums[i] == x){
                i++;
            }
            check[x]++;
        }
        int ans = 0;
        for(int i = 0; i <= 100; i++){
            if(check[i] == 1) ans++;
        }
        return ans;
    }
};