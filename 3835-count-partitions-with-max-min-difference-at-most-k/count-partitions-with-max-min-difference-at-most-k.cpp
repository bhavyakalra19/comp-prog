class Solution {
public:
    
const int MOD = 1e9 + 7;

int countPartitions(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> dp(n + 1), prefix(n + 2);
    dp[0] = 1;
    prefix[1] = 1;

    deque<int> minQ, maxQ;
    int left = 0;

    for (int right = 1; right <= n; ++right) {
        int val = nums[right - 1];

        // Maintain monotonic queues for max and min
        while (!minQ.empty() && nums[minQ.back()] >= val)
            minQ.pop_back();
        minQ.push_back(right - 1);

        while (!maxQ.empty() && nums[maxQ.back()] <= val)
            maxQ.pop_back();
        maxQ.push_back(right - 1);

        // Shrink window if invalid
        while (nums[maxQ.front()] - nums[minQ.front()] > k) {
            if (minQ.front() == left)
                minQ.pop_front();
            if (maxQ.front() == left)
                maxQ.pop_front();
            left++;
        }

        // dp[right] = sum of dp[left..right-1]
        dp[right] = (prefix[right] - prefix[left] + MOD) % MOD;
        prefix[right + 1] = (prefix[right] + dp[right]) % MOD;
    }

    return dp[n];
}

};
