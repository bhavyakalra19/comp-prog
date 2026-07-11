class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        long long mod = 1e9 + 7;
        unordered_set<int> ks;
        
        // Always include 2 as a baseline option for Alice
        ks.insert(2); 

        // 1. EXTRACT UNIQUE PRIME FACTORS
        for (int x : nums) {
            int d = 2;
            while (d * d <= x) {
                if (x % d == 0) {
                    ks.insert(d);
                    // Divide out the factor completely to ensure we only get primes
                    while (x % d == 0) {
                        x /= d;
                    }
                }
                d++;
            }
            // If x is still greater than 1, it is prime itself
            if (x > 1) {
                ks.insert(x);
            }
        }

        long long best_diff = -1e18; // Use a very small number for initialization
        int best_k = -1;

        // 2. KADANE'S ALGORITHM FOR EACH PRIME FACTOR
        for (int k : ks) {
            long long current_sum = 0;
            long long max_sum = -1e18;
            
            for (int v : nums) {
                long long val = (v % k == 0) ? v : -v;
                
                // Correct Kadane's logic: standard max(val, current + val)
                current_sum = max(val, current_sum + val);
                max_sum = max(max_sum, current_sum);
            }

            // Update best score difference
            if (max_sum > best_diff || (max_sum == best_diff && (best_k == -1 || k < best_k))) {
                best_diff = max_sum;
                best_k = k;
            }
        }

        // 3. SAFE MODULO ARITHMETIC
        // best_diff could technically be negative, so we handle negative modulo safely
        long long ans = (best_diff % mod * best_k % mod) % mod;
        if (ans < 0) {
            ans += mod;
        }
        
        return ans;
    }
};