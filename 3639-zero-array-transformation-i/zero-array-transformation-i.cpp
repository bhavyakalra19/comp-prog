class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> cnt(n+1,0);
        for(auto &q: queries){
            cnt[q[0]]++;
            cnt[q[1] + 1]--;
        }
        int sm = 0;
        for(int i = 0; i < n; i++){
            sm += cnt[i];
            if(sm < nums[i]) return false; 
        }
        return true;
    }
};