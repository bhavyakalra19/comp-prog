class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0;
        int cnt2 = 0;
        int n1 = INT_MAX;
        int n2 = INT_MAX;
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && nums[i] != n2){
                cnt1 = 1;
                n1 = nums[i];
            }else if(n1 == nums[i]){
                cnt1++;
            }else if(cnt2 == 0){
                cnt2 = 1;
                n2 = nums[i];
            }else if(n2 == nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == n1){
                cnt1++;
            }else if(nums[i] == n2){
                cnt2++;
            }
        }
        if(cnt1 > n/3 && cnt2 > n/3){
            return {n1, n2};
        }else if(cnt1 > n/3){
            return {n1};
        }else if(cnt2 > n/3){
            return {n2};
        }
        return {};
    }
};