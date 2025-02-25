class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<pair<int,int>> check;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int n = nums.size();
        int hg = nums[n-1];
        for(int i = 0; i < n; i++){
            mp[nums[i]] += 1;
        }
        int i = 0;
        int j = 0;
        int mx = max(0,nums[0] - k);
        int ans = 1;
        int count = 0;
        while(mx <= hg){
            while(j < n && (nums[j] - k) <= mx){
                j++;
            }
            while(i < j && (nums[i] + k) < mx){
                i++;
            }
            if(j-i <= numOperations){
                ans = max(ans, j - i);
            }else{
                ans = max(ans, mp[mx] + min(j-i-mp[mx], numOperations));
            }
            mx += 1;
            if((j-i == 1) && j < n){
                mx = max(0,nums[j] - k);
                j++;
            }
        }
        return ans;
    }
};