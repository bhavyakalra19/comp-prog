class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] == 2){
                ans.push_back(-1);
            }else{
                int check = 0;
                int num = nums[i];
                while((num & 1) == 1){
                    num = num >> 1;
                    check++;
                }
                ans.push_back(nums[i] - (1 << (check - 1)));
            }
        }
        return ans;
    }
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      