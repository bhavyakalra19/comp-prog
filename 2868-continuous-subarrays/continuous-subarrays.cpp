class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
       int n = nums.size();
       int i = 0;
       int j = 0;
       unordered_map<int,int> mp;
       long long ans = 0; 
       while(i < n){
            while(j < i && (abs(nums[i] - nums[j]) > 2 || mp[nums[i] - 3] != 0 || mp[nums[i] + 3] != 0)){
                mp[nums[j]] -= 1;
                j++;
            }

            while(i < n && abs(nums[i] - nums[j]) <= 2 && (mp[nums[i] - 3] == 0) && (mp[nums[i] + 3] == 0)){
                mp[nums[i]] += 1;
                i++;
                ans += i - j;
            }
       }
       return ans;
    }
};