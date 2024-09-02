class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int ps = chalk[0];
        if(ps > k){
            return 0;
        }
        for(int i = 1; i < n; i++){
            ps += chalk[i];
            if(ps > k){
                return i;
            }
        }
        k = k % ps;
        for(int i = 0; i < n; i++){
            if(chalk[i] > k){
                return i;
            }
            k -= chalk[i];
        }
        return n-1;
    }
};