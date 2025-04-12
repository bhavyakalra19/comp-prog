class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int mx = 0;
        int cnt = 0;
        if(n == 1) return 0; 
        for(int i = 0; i < n; i++){
            mx = max(mx, i + nums[i]);
            if(i == curr){
                curr = mx;
                cnt++;
                if(curr >= n-1) break;
            }
        }
        return cnt;
    }
};