class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans{-1,-1};
        if(n == 0 || (target > nums[n-1]) || (target < nums[0])){
            return ans;
        }
        int st = 0;
        int en = n-1;
        int mid;
        while(st <= en){
            mid = (st + en)/2;
            if(nums[mid] == target){
                break;
            }else if(nums[mid] < target){
                st = mid + 1;
            }else{
                en = mid - 1;
            }
        }
        if(nums[mid] == target){
            int en1 = mid;
            int st1 = mid;
            int fir = en1;
            while(st <= en1){
                mid = (st + en1)/2;
                if(nums[mid] < target){
                    st = mid + 1;
                }else{
                    fir = mid;
                    en1 = mid - 1;
                }
            }
            int pos = st1;
            while(st1 <= en){
                mid = (st1 + en)/2;
                if(nums[mid] > target){
                    en = mid - 1;
                }else{
                    pos = mid;
                    st1 = mid + 1;
                }
            }
            return {fir,pos};
        }
        return ans;
    }
};