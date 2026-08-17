class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int getAns(int st, int en, vector<int> &ps){
        if(st == en){
            return 0; 
        }
        if(dp[st][en] != -1) return dp[st][en];
        int ans = 0;
        for(int i = st; i < en; i++){
            int firstHalf = ps[i+1] - ps[st];
            int secondHalf = ps[en+1] - ps[i+1];
            if(firstHalf < secondHalf){
                ans = max(ans, firstHalf + getAns(st, i, ps)); 
            }else if(firstHalf > secondHalf){
                ans = max(ans, secondHalf + getAns(i+1, en, ps));
            }else{
                ans = max(ans, firstHalf + max(getAns(st, i, ps), getAns(i+1, en, ps)));
            }  
        }
        return dp[st][en] = ans;
    }

    int stoneGameV(vector<int>& nums) {
        n = nums.size();
        vector<int> ps(n+1, 0);
        int cs = 0;
        dp.resize(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            cs += nums[i];
            ps[i+1] = cs;
        }
        return getAns(0, n-1, ps);
    }
};

