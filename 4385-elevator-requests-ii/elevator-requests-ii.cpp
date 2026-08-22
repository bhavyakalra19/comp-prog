class Solution {
public:
    long long getAns(vector<int> &check, int i, int j, int &n, int k,  vector<vector<vector<long long>>> &dp){
        if(i == 0 && j == n+1){
            return 0;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int prev = (k == 0) ? i : j-2;
        long long ans = LONG_MAX;
        long long remaining = n - j + 1 + i;
        if(i != 0){
            ans = remaining * (abs(check[prev] - check[i-1])) + getAns(check, i-1, j, n, 0, dp);
        }
        if(j != n+1){
            ans = min(ans, remaining * (abs(check[prev] - check[j-1])) + getAns(check, i, j+1, n, 1, dp));
        }
        return dp[i][j][k] = ans;
    }

    int getPoint(vector<int> &check, int &n, int &start){
        int st = 0;
        int en = n-1;
        int ans = 0;
        while(st <= en){
            int mid = (st + en)/2;
            if(check[mid] <= start){
                ans = mid;
                st = mid + 1;
            }else{
                en = mid - 1;
            }
        }
        return ans;
    }

    long long elevatorRequests(int m, int start, vector<int>& requests) {
        unordered_set<int> st;
        vector<int> check;
        for(auto &a : requests){
            if(st.find(a) == st.end()){
                st.insert(a);
                check.push_back(a);
            }
        }
        int n = check.size();
        int penalty = 0;
        if(st.find(start) == st.end()){
            st.insert(start);
            check.push_back(start);
            n += 1;
        }
        sort(check.begin(), check.end());
        int idx = getPoint(check, n, start);
        vector<vector<vector<long long>>> dp(n+2, vector<vector<long long>>(n+2, vector<long long>(2, -1)));
        return getAns(check, idx, idx + 2, n, 0, dp);
    }
};

// now main problem is we can remove k as we can keep track where did he came from 0 means from left to right , 1 means right to left
// for penaly we add x penalty then x + y, then x + y + z so multiply x with remaining platforms to remove it from dp array

// 0 1 2 3 4 5 6

// n - j + 1 + i
// 2 4
// 3 5