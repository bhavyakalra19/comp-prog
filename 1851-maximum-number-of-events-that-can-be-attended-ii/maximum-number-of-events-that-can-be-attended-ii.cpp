class Solution {
public:
    int n;
    int getNextIdx(vector<vector<int>> &events, int st, int mx){
        if(mx > events[n-1][1]){
            return n;
        }
        int ans;
        int en = n-1;
        while(st <= en){
            int mid = (st + en)/2;
            if(events[mid][0] < mx){
                st = mid + 1;
            }else{
                en = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

    int getAns(vector<vector<int>> &events, int k, int idx, vector<vector<int>> &dp){
        if(idx >= n || k == 0){
            return 0;
        }
        if(dp[idx][k] != -1) return dp[idx][k];
        int ans = getAns(events, k, idx + 1, dp);
        int getNext = getNextIdx(events, idx + 1, events[idx][1] + 1);
        ans = max(ans, events[idx][2] + getAns(events, k-1, getNext, dp));
        return dp[idx][k] = ans;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return getAns(events, k, 0, dp);
    }
};
