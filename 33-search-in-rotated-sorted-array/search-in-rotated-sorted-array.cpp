class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int en = n-1;
        while(st <= en){
            int mid = (st + en)/2;
            if(nums[mid] == target){
                return mid;
            }if(nums[mid] >= nums[st]){
                if(target >= nums[st] && target < nums[mid]){
                    en = mid-1;
                }else{
                    st = mid+1;
                }
            }else{
                if(target <= nums[en] && target >= nums[mid]){
                    st = mid + 1;
                }else{
                    en = mid - 1;
                }
            }
        }
        return -1;
    }
};