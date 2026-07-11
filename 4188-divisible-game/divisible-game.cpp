class Solution {
public:
    bool isPrime(int n) {
        // Check if n is 2 or 3
        if (n == 2 || n == 3)
            return true;

        // Check whether n is divisible by 2 or 3
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        // Check numbers of the form 6k ± 1 up to √n
        for (int i = 5; i * i<=n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }

    int divisibleGame(vector<int>& nums) {
        unordered_set<int> st;
        int mod = 1e9 + 7;
        int n = nums.size();
        int high = 1;
        for(auto &a: nums){
            high = max(high, a);
        }
        
        if(high == 1){
            return (2 * -1 + mod) % mod;
        }
        long long mx_diff = 0;
        int k = 0;
        for(int a = 2; a <= high; a++){
            if(!isPrime(a)) continue;
            long long sum = 0;
            long long curr_mx = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] % a == 0){
                    sum += nums[i];
                }else{
                    sum -= nums[i];
                }
                curr_mx = max(curr_mx, sum);
                if(sum < 0) sum = 0;
            }
            if(mx_diff < curr_mx){
                mx_diff = curr_mx;
                k = a;
            }
        }
        return (mx_diff * k) % mod;
    }
};

// k > 1

// l and r


// 4 2 1 4 4

// 4 * 9 

// 2 * 