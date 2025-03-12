class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int en = n-1;
        int mn = -1;
        while(st <= en){
            int mid = (st + en)/2;
            if(nums[mid] >= 0){
                en = mid - 1;
            }else{
                mn = mid;
                st = mid + 1;
            }
        }
        st = 0;
        en = n-1;
        int mx = n;
        while(st <= en){
            int mid = (st + en)/2;
            if(nums[mid] > 0){
                mx = mid;
                en = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return max(n - mx, mn + 1);
    }
};