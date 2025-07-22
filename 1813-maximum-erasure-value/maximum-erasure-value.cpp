class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        bool cnt = false;
        int j = 0;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 2){
                cnt = true;
            }
            sum += nums[i];
            while(j < i && cnt){
                if(mp[nums[j]] == 2) cnt = false;
                sum -= nums[j];
                mp[nums[j++]] -= 1;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};