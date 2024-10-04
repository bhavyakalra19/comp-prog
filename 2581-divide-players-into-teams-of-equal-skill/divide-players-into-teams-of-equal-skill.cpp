class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long sum = 0;
        int freq[1001] = {0};
        int mn = 1000;
        int mx = 1;
        for(auto x : skill){
            sum += x;
            freq[x] += 1;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        if(sum %(n/2) != 0){
            return -1;
        }
        int check = (mx + mn);
        long long ans = 0;
        long i;
        long j;
        for(i = mn, j = mx; i < j; i++, j--){
            long fi = freq[i];
            long fj = freq[j];
            if(i+j != check || fi != fj){
                return -1;
            }
            ans += (i * j * fi);
        }
        ans += (i==j && i*2 == check) ? freq[i] * i * i / 2LL : 0LL;
        return ans;
    }
};