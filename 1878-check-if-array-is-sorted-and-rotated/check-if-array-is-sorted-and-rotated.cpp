class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int mx;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                if(cnt) return false;
                cnt++;
                mx = nums[0];
            }
            if(cnt && nums[i] > mx){
                return false;
            }
        }
        return true;
    }
};