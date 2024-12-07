class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int st = 1;
        int mx = 1;
        for(auto a : nums){
            mx = max(mx, a);
        }
        while(st < mx){
            int mid = (mx + st)/2;
            int k = 0;
            for(auto a : nums){
                k += (a - 1)/mid;
            }
            if(k <= maxOperations){
                mx = mid;
            }else{
                st = mid + 1;
            }
        }
        return mx;
    }
};
