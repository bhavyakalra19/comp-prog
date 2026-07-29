class Solution {
public:
    long long get_ncr(int n, int r, int &k){
        long long ans = 1;
        if(n == r) return 1;
        if(n-r < r) r = n - r;
        for(int i = 1; i <= r; i++){
            ans *= (n-i+1);
            ans /= i;
            if(ans > k) return INT_MAX;
        }
        return ans;
    }


    long long get_ways(vector<int> &count, int c, int n, int k){
        count[c] -= 1;
        n -= 1;
        long long ways = 1;
        
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                long long current_ncr = get_ncr(n, count[i], k);
            
                // If the combination alone exceeds k, bail out immediately
                if (current_ncr >= k) {
                    count[c] += 1;
                    return k + 1; 
                }
                
                // Precise Inverse Check: safely checks (ways * current_ncr >= k)
                if (ways >= (k + current_ncr - 1) / current_ncr) {
                    count[c] += 1;
                    return k + 1;
                }
                
                ways *= current_ncr;
                n -= count[i];
            }
        }
        count[c] += 1;
        return ways;
    }

    // const long long INF = 1e18; // Adjust to your specific problem's INF

    // long long get_ncr(int n, int r) {
    //     if (r < 0 || r > n) return 0;
        
    //     // 1. The Symmetry Optimization: forces the loop to run as few times as possible
    //     if (r > n - r) r = n - r; 
        
    //     long long ans = 1;
    //     if (n == r || r == 0) return 1;
        
    //     for (int i = 1; i <= r; i++) {
    //         // 2. The 128-bit cast: prevents overflow during the multiplication step
    //         __int128_t step = (static_cast<__int128_t>(ans) * (n - i + 1)) / i;
            
    //         // 3. The INF cap: stops calculation if it gets too large
    //         if (step >= INF) return INF;
    //         ans = static_cast<long long>(step);
    //     }
    //     return ans;
    // }

    // long long get_ways(vector<int> &count, int c, int n) {
    //     count[c] -= 1;
    //     n -= 1;
    //     long long ways = 1;
        
    //     for (int i = 0; i < 26; i++) {
    //         if (count[i] > 0) {
    //             long long current_ncr = get_ncr(n, count[i]);
                
    //             // Cast to 128-bit before multiplying combinations together to prevent overflow
    //             __int128_t next_ways = static_cast<__int128_t>(ways) * current_ncr;
                
    //             if (next_ways >= INF) {
    //                 count[c] += 1; // Restore before returning
    //                 return INF;
    //             }
                
    //             ways = static_cast<long long>(next_ways);
    //             n -= count[i];
    //         }
    //     }
    //     count[c] += 1;
    //     return ways;
    // }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> count(26, 0);
        for(auto &a : s){
            int x = a - 'a';
            count[x]++; 
        }
        // check for odd one as we have fill the middle position with to left out string to be in palindrome
        int odd = -1;
        for(int i = 0; i < 26; i++){
            if(count[i] % 2){
                count[i]--;
                odd = i;
            }
            count[i] /= 2;
        }
        string str = s;
        n = n/2;
        if(odd != -1){
            str[n] = (char)(odd + 'a');
        }
        int left = n/2;
        for(int i = 0; i < n; i++){
            int curr_ways = 0;
            for(int j = 0; j < 26; j++){
                if(count[j] > 0){
                    long long total_ways = get_ways(count, j, n-i, k);
                    // cout << i << " " << j << " " << total_ways << " " << k << endl;
                    if(total_ways >= k){
                        str[i] = (char)(j + 'a');
                        count[j]--;
                        break;
                    }else if (total_ways < k){
                        k -= total_ways;
                    }
                }
                if(j == 25) return "";
            }
        }
        int sz = str.size();
        for(int i = 0; i < sz/2; i++){
            str[sz - i - 1] = str[i];
        }
        return str;
    }
};

// xxn
// n x x