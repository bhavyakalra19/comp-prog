class Solution {
public:
    long long mod = 1000000007;

    long long power_mod(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp = exp / 2;
        }
        // this function multiplies a number by itself n times in O(logn)
        return result;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1) return nums;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i]);
            pq.push({nums[i],i});
        }
        while(k > 0 &&  pq.top().first * multiplier <= mx){
            auto it = pq.top();
            pq.pop();
            pq.push({it.first * multiplier, it.second});
            k--;
        }

        long long curr = power_mod(multiplier, k/n) % mod;
        k = k%n;
        while (!pq.empty()) {
            long long val = pq.top().first;
            int ind = pq.top().second; pq.pop();
            if(k > 0) {
                --k;
                nums[ind] = (((multiplier * curr) % mod) * val) % mod; 
            } else {
                nums[ind] = (curr * val) % mod;
            }
        }
        return nums;
    }
};