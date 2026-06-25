class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //prefix sum and calculate sum
        int n = nums.size();
        int curr = n;
        vector<int> check(2 * n + 1, 0);
        // target -> +1, others -> -1
        //find all prefix sum encounters lesser than curr as there will be more target values there -> very obvious 
        int mn = n;
        int ans = 0;
        check[n] = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                curr += 1;
            }else{
                curr -= 1;
                mn = min(mn, curr);
            }
            for(int j = mn; j < curr; j++){
                ans += check[j];
            }
            check[curr]++;
        }
        return ans;
    }
};
// n n-1, n, n+1 , n