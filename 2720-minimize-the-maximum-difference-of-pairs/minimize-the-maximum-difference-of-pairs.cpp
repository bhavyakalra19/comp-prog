class Solution {
public:
    bool checkDiff(vector<int> &nums, int &mid, int p, int &n){
        int i = 0;
        while(i + 1 < n){
            if(nums[i+1] - nums[i] <= mid){
                p--;
                i++;
                if(p == 0) return true;
            }
            i++;
        }
        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int high = nums[n-1] - nums[0];
        int low = 0;
        int ans = -1;
        if(p == 0) return 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(checkDiff(nums, mid, p, n)){
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};