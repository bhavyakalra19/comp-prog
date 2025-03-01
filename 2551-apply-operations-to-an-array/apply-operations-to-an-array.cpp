class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int cnt = 0;
        for(int i = 0; i < n - 1;  i++){
            if(nums[i] == 0){
                cnt++;
            }else if(nums[i] == nums[i+1]){
                ans.push_back(nums[i] * 2);
                nums[i+1] = 0;
            }else{
                ans.push_back(nums[i]);
            }
        }
        if(nums[n-1] == 0){
            cnt++;
        }else{
            ans.push_back(nums[n-1]);
        }
        while(cnt > 0){
            ans.push_back(0);
            cnt--;
        }
        return ans;
    }
};