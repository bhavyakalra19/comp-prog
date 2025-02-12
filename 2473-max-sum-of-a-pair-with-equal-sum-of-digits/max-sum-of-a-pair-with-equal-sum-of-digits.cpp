class Solution {
public:
    int sumOfDigits(int num){
        int sm = 0;
        while(num > 0){
            sm += num % 10;
            num /= 10;
        }
        return sm;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int check = sumOfDigits(nums[i]);
            if(mp.find(check) != mp.end()){
                ans = max(ans, mp[check] + nums[i]);
                mp[check] = max(mp[check], nums[i]);
            }else{
                mp[check] = nums[i];
            }
        }
        return ans == 0 ? -1 : ans;
    }
};