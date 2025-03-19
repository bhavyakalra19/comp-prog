class Solution {
public:
    int getAns(vector<int> &nums, int &n, int mid){
        int ans = 0;
        int i = 0;
        while(i < n){
            if(nums[i] <= mid){
                ans++;
                i++;
            }
            i++;
        }
        return ans;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int st = 0;
        int en = *max_element(nums.begin(), nums.end());
        int ans = en;
        while(st <= en){
            int mid = (st + en)/2;
            int check = getAns(nums, n, mid);
            if(check >= k){
                ans = mid;
                en = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
};