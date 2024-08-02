class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int oc = 0;
        int mc = 0;
        for(int i = 0; i < n; i++){
            oc += nums[i];
        }
        if(oc == 0 || oc == n){
            return 0;
        }
        for(int i = 0; i < oc; i++){
            mc += nums[i];
        }
        int maxOne = mc;
        for(int i = 0; i < n; i++){
            mc -= nums[i];
            mc += nums[(i + oc) % n];
            maxOne = max(maxOne, mc);
        }
        return oc - maxOne;
    }
};