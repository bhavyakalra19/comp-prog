class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odd = 0;
        int even = 0;
        int o = 0;
        int e = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] % 2 == 0){
                even++;
                e = o + 1;
            }else{
                odd++;
                o = e + 1;
            }
        }
        return max(even, max(odd, max(e,o)));
    }
};