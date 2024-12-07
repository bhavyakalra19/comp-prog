class Solution {
public:
    bool checkNums(vector<int> nums, int ch, int mx){
        int ans = 0;
        for(auto a : nums){
            ans += (a - 1)/ch;
            if(ans > mx){
                return false;
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int st = 1;
        int mx = 1;
        for(auto a : nums){
            mx = max(mx, a);
        }
        while(st < mx){
            int mid = (mx + st)/2;
            if(checkNums(nums, mid, maxOperations)){
                mx = mid;
            }else{
                st = mid + 1;
            }
        }
        return mx;
    }
};
