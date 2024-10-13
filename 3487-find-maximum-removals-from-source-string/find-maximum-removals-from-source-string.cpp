class Solution {
public:
    int m;
    int n;
    string main;
    string second;
    vector<vector<long long>> dp;
    vector<bool> isThere;
    long long getAns(int i, int j){
        if(j == n){
            int count = 0;
            for(;i < m; i++){
                count += isThere[i] == true ? 1 : 0;
            }
            return count;
        }
        if(i == m || (m - i  < n - j)){
            return INT_MIN;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(isThere[i]){
            if(main[i] == second[j]){
                return dp[i][j] = max(1 + getAns(i+1,j), getAns(i+1,j+1));
            }
            return dp[i][j] = 1 + getAns(i+1,j);
        }
        if(main[i] == second[j]){
            return dp[i][j] = getAns(i+1, j+1);
        }
        return dp[i][j] = getAns(i+1, j);
    } 

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        m = source.size();
        n = pattern.size();
        main = source;
        second = pattern;
        isThere.resize(m,false);
        for(auto&it:targetIndices){
            isThere[it] = true;
        }
        dp.resize(m,vector<long long>(n,-1));
        if(main == second || targetIndices.size() == 0){
            return 0;
        }
        return getAns(0,0);
    }
};