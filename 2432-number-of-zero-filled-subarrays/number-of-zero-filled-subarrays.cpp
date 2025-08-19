class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt = 0;
        for(auto &a : nums){
            if(a == 0){
                cnt++;
            }else{
                cnt = 0;
            }
            ans += cnt;
        }
        return ans;
    }
};