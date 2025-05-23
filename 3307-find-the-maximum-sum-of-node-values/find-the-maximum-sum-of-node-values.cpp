class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        long long ans = 0;
        int mn = INT_MAX;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if((nums[i] ^ k) > nums[i]){
                ans = ans + (nums[i] ^ k);
                mn = min(mn, (nums[i] ^ k) - nums[i]);
                cnt++;
            }else{
                mn = min(mn, nums[i] - (nums[i] ^ k));
                ans = ans + nums[i];
            }
        }
        if(cnt % 2 == 0){
            return ans;
        }
        cout << mn << endl;
        return ans - mn;
    }
};


