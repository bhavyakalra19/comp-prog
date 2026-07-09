class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> nums(n+1);
        vector<int> power10(n+1);
        vector<long long> sums(n+1);
        
        int mod = 1e9 + 7;
        long long sum = 0;
        int ten = 0;
        long long num = 0;
        nums[0] = 0;
        power10[0] = 0;
        sums[0] = 0;

        for(int i = 0; i < n; i++){
            if(s[i] != '0'){
                int x = s[i] - '0';
                sum = (sum + x) % mod;
                num = (num * 10 + x) % mod;
                ten += 1;
            }
            nums[i+1] = num;
            sums[i+1] = sum;
            power10[i+1] = ten;
        }
        int mx = power10[n];
        vector<int> power(mx+1);
        power[0] = 1;
        for(int i = 1; i <= mx; i++){
            power[i] = (1LL * power[i-1] * 10) % mod;
        }

        vector<int> ans;
        for(auto &q : queries){
            int i = q[0];
            int j = q[1] + 1;
            long long curr_sum = (sums[j] - sums[i] + mod) % mod;

            int k = power[power10[j] - power10[i]];
            int curr = ((nums[j] - (nums[i] * k) % mod + mod) % mod * curr_sum + mod) % mod;
            ans.push_back(curr);
        }
        return ans;
    }  
};

// 0 0 0
// 1 1 10
// 1 1 10
// 12 3 100
// 12 3 100
// 123 6 1000
// 123 6 1000
// 123 6 1000


// int power = (nums[j] - (nums[i] * (power[j+1] / power[i]))) * sum;