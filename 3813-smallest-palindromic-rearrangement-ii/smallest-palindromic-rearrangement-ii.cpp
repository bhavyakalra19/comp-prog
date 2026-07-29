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