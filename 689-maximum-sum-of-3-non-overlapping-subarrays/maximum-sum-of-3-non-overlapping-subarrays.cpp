class Solution {
public:
    // int getAns(vector<int> &nums, int &k, int idx, int n, vector<vector<int>> &dp){
    //     if(n == 3){
    //         return 0;
    //     }
    //     if(idx >= nums.size()){
    //         return 0;
    //     }
    //     if(dp[idx][n] != -1){
    //         return dp[idx][n];
    //     }
    //     int nt = getAns(nums, k, idx + 1, n, dp);
    //     int tk = nums[idx] + getAns(nums, k, idx + k, n+1,dp);
    //     return dp[idx][n] = max(nt, tk);
    // }

    // void checkAns(vector<int> &sumArray, int &k, int idx, vector<int> &res, int t, vector<vector<int>> &dp){
    //     if(idx >= sumArray.size() || t == 3 || res.size() == 3){
    //         return;
    //     }
    //     int take = sumArray[idx] + getAns(sumArray, k, idx + k, t+1 , dp);
    //     int notTake = getAns(sumArray, k, idx+1, t, dp);
    //     if(take >= notTake){
    //         res.push_back(idx);
    //         checkAns(sumArray, k, idx+k, res, t+1, dp);
    //     }else{
    //         checkAns(sumArray, k, idx+1, res, t, dp);
    //     }
    // }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sumArray;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(i >= k){
                sumArray.push_back(sum);
                sum -= nums[i-k];
            }
            sum += nums[i];
        }
        sumArray.push_back(sum);
        // vector<vector<int>> dp(sumArray.size(), vector<int>(4,-1));
        vector<int> res;
        // checkAns(sumArray, k, 0, res, 0, dp);
        int c = sumArray.size();
        vector<int> left;
        vector<int> right;
        int best;
        int mx = 0;
        for(int i = 0; i < c; i++){
            if(mx < sumArray[i]){
                best = i;
                mx = sumArray[i];
            }
            left.push_back(best);
        }
        mx = 0;
        for(int i = c - 1; i >= 0; i--){
            if(mx <= sumArray[i]){
                best = i;
                mx = sumArray[i];
            }
            right.push_back(best);
        }
        reverse(right.begin(), right.end());
        mx = 0;
        for(int i = k; i < c - k; i++){
            int sum = sumArray[i] + sumArray[left[i - k]] + sumArray[right[i+k]];
            if(mx < sum){
                res = {left[i-k],i,right[i+k]};
                mx = sum;
            }
        }
        return res;
    }
};