class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        int even_n = n / 2;
        int odd_n = (n + 1) / 2;

        int even_m = m/2;
        int odd_m = (m+1)/2;
        ans = (1LL * even_n * odd_m) + (1LL * odd_n * even_m);
        return ans;
    }
};
