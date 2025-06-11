class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int mod = 1e9 + 7;
        for(int i = 1; i < n; i++){
            if(complexity[i] <= complexity[0]) return 0;
        }
        long long ans = 1;
        for(long long i = 1; i < n; i++){
            ans = (ans * i) % mod;
        }
        return ans;
    }
};
