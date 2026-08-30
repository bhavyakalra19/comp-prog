class Solution {
public:
    pair<long long, long long> getNums(long long n, int depth){
        long long check = 10;
        int cnt = 1;
        while(n / check > 0){
            check *= 10;
            cnt++;
        }
        int mx = cnt - depth;
   
        long long c = 1;
        while(mx > 0){
            c *= 10;
            mx--;
        }
        long long y = n % c;
        long long x = n / c;
        return {x, y};
    }
    
    long long mod = 1e9 + 7;

    void getSum(long long &x, long long &y){
        long long ans = 1;
        while(y > 0){
            if(y & 1){
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            y = y >> 1;
        }
        x = ans;
    }

    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        for(auto &a : nums){
            pair<long long, long long> c = getNums(a / 10, a % 10);
            getSum(c.first, c.second);
            sum = (sum + c.first) % mod;
        }
        return sum;
    }
};

// width = nums[i] % 10;
// d = nums[i] / 10;


// 1 1 1 1 1
