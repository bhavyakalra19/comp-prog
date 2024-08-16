class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mn = 0;
        int mx = nums.back() - nums.front();
        while(mn < mx){
            int md = mn + (mx - mn)/2;
            if(countCheck(nums, md) < k){
                mn = md + 1;
            }else{
                mx = md;
            }
        }
        return mx;
    }

    int countCheck(vector<int> nums, int md){
        int count = 0;
        int left = 0;
        for(int right = 1; right < nums.size(); right++){
            while(nums[right] - nums[left] > md){
                ++left;
            }
            count += right - left;
        }
        return count;
    }
};