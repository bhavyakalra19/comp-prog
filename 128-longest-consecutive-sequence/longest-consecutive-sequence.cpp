class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> mp;
        if(n == 0) return 0;
        int ans = 1;
        for(int i = 0; i < n; i++){
            mp.insert(nums[i]);
        }

        for(auto &a : mp){
            if(mp.find(a - 1) == mp.end()){
                int cnt = 0;
                int val = a;
                while(mp.find(val) != mp.end()){
                    cnt++;
                    val += 1;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};