class Solution {
public:
    void updateBits(vector<int> &check, int num, int val){
        int nm = num;
        int i = 0;
        while(nm > 0){
            if((nm & 1) == 1){
                check[i] += val;
            }
            i++;
            nm >>= 1;
        }
    }

    int getNum(vector<int> check){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(check[i] > 0){
                ans += (1 << i);
            }
        }
        return ans;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> check(32,0);
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int t = 0;
        while(i < n){
            updateBits(check,nums[i++],1);
            while(j < i && getNum(check) >= k){
                ans = min(ans,i-j);
                updateBits(check,nums[j++],-1);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};