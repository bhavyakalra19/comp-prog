class Solution {
public:
    int n;
    int getAns(vector<int> &stones, int idx, int jump, vector<vector<int>> &dp){
        if(idx == n-1) return true;
        bool check = false;
        if(dp[idx][jump] != -1) return dp[idx][jump];
        
        int i = idx;
        int j1 = jump - 1;
        if(j1 > 0){
            while(i < n && stones[i] < (stones[idx] + j1)){
                i++;
            }
            if(i < n && stones[i] == stones[idx] + j1){
                check = check | getAns(stones, i, j1, dp);
            }
        }
        int j2 = jump;
        while(i < n && stones[i] < (stones[idx] + j2)){
            i++;
        }
        if(i < n && stones[i] == stones[idx] + j2){
            check = check | getAns(stones, i, j2, dp);
        }

    
        int j3 = jump + 1;
        while(i < n && (stones[i] < (stones[idx] + j3))){
            i++;
        }
        if(i < n && (stones[i] == (stones[idx] + j3))){
            check = check | getAns(stones, i, j3, dp);
        }
        return dp[idx][jump] = check;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();
        vector<vector<int>> dp(n, vector<int>(1000, -1));
        if(stones[1] > 1) return false;
        int a = getAns(stones, 1, 1, dp);
        return a;
    }
};
