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
        long long ans = 0;
        check[n] = 1;
        long long ps = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){

                ps += check[curr];

                curr += 1;
            }else{
                curr -= 1;
                ps -= check[curr];
            }
 
            check[curr]++;
            ans +=ps;
        }
        return ans;
    }
};
// n n-1, n, n+1 , n

// 0 -1, -2, -3 -2 -3