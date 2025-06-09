class Solution {
public:
    long long mod = 1e9 + 7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1,0);
        vector<long long> ps(n+3, 0);
        ps[n] = 1;
        deque<int> minq;
        deque<int> maxq;
        int right = n-1;
        for(int curr = n-1; curr >= 0; curr--){
            while(!minq.empty() && nums[curr] < nums[minq.back()]){
                minq.pop_back();
            }
            minq.push_back(curr);

            while(!maxq.empty() && nums[curr] > nums[maxq.back()]){
                maxq.pop_back();
            }
            maxq.push_back(curr);

            while(nums[maxq.front()] - nums[minq.front()] > k){
                if(maxq.front() == right){
                    maxq.pop_front();
                }
                if(minq.front() == right){
                    minq.pop_front();
                }
                right--;
            }
            dp[curr] = (ps[curr + 1] - ps[right + 2] + mod) % mod;
            ps[curr] = (ps[curr + 1] + dp[curr]) % mod;
        }
        return dp[0];
    }
};