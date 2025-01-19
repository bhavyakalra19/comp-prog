class Solution {
public:
    vector<long long> mp;
    const int mod = 1e9 + 7;
    typedef long long ll;
    vector<ll> f, factInv;

    Solution() {
        f.resize(100000);
        factInv.resize(100000);
        f[0] = 1;
        for(int i = 1; i < 100000; i++){
            f[i] = f[i-1] * i % mod;
        }
        
        factInv[100000 - 1] = binpow(f[100000 - 1], mod - 2);
        for(int i = 100000 - 2; i >= 0; i--){
            factInv[i] = factInv[i+1] * (i+1) % mod;
        }
    }

    ll binpow(ll a, ll b){
        ll res = 1;
        while (b) {
            if (b % 2) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }

    ll comb(ll n, ll r) {
        if (r > n) return 0;
        return f[n] * factInv[r] % mod * factInv[n - r] % mod;
    }

    long long fc(int a){
        if(a == 1 || a == 0){
            return 1;
        }
        if(mp[a] != -1){
            return mp[a];
        }
        return mp[a] = (a * fc(a-1)) % mod;
    }

    long long ncr(int a, int b){
        if(a < b){
            return 0;
        }
        return ((fc(a) / (fc(b)) % mod) * ((fc(a) / fc(a - b))) % mod);
    }

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        for(int a : nums){
            ans += 2 * a;
        }
        ans = ans % mod;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            for(int j = 1; j < k; j++){
                ans = (ans + (nums[i] * comb(n - i - 1, j) % mod)) % mod;
                ans = (ans + (nums[i] * comb(i,j)) % mod) % mod;
            }
        }
        return ans;
    }
};
