class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int cnt = 0;
        for(auto &a : nums) if(a % 2 == 0) cnt++;
        for(int i = 0; i < nums.size(); i++){
            if(i < cnt){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
        }
        return nums;
    }
};