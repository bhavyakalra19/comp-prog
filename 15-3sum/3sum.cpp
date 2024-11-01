class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        if(nums[0] > 0){
            return ans;
        }
        for(int i = 0; i < n-2; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = n-1;

            while(j < k){
                int total = nums[i] + nums[j] + nums[k];
                if(total > 0){
                    k--;
                }else if(total < 0){
                    j++;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(j < k && nums[j-1] == nums[j]){
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};
