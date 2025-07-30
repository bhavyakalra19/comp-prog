class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        bool cont = false;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == mx){
                cont = true;
                cnt++;
            }else if((nums[i] & mx) == mx){
                cnt++;
            }else{
                if(cont){
                    ans = max(ans, cnt);
                }
                cont = false;
                cnt = 0;
            }
        }
        if(cont){
            ans = max(ans, cnt);
        }
        return ans;
    }
};