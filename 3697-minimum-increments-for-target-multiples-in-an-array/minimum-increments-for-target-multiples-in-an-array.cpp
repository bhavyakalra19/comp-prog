class Solution {
public:
    long long getAns(vector<int> & nums, int idx, int assign, int &am, vector<vector<int>> &dp, vector<int> &target){
        if(am == assign) return 0;
        if(idx == nums.size()) return 1e9;
        if(dp[idx][assign] != -1) return dp[idx][assign];

        long long notTake = getAns(nums,idx+1,assign,am,dp,target);
        long long take = 1e9;
        for(int i = 0; i < target.size(); i++){
            if((assign & (1 << i)) == 0){
                long long cal = (nums[idx] % target[i]);
                cal = (cal == 0 ? 0 : target[i] - cal);
                take = min(take, cal + getAns(nums, idx + 1, assign | (1 << i), am, dp, target));
            }
        }
        return dp[idx][assign] = min(take, notTake);
    }

    void dfs(string str, int idx, int len, vector<string> &check){
        if(idx == len){
            check.push_back(str);
            return;
        }
        dfs(str, idx + 1, len, check);
        str[idx] = '1';
        dfs(str, idx + 1, len, check);
        str[idx] = '0';
    }
    
    int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    // Function to return LCM of two numbers 
    int getLcm(long long a, long long b){
        long long ans = (a / gcd(a, b)) * b;
        return ans > INT_MAX ? INT_MAX : ans;
    }

    int minimumIncrements(vector<int>& nums, vector<int>& target) {
        vector<string> check;
        string a = "";
        for(int i = 0; i < target.size(); i++){
            a += '0';
        }
        dfs(a, 0, 4, check);
        long long ans = INT_MAX;
        for(auto &s : check){
            int a = 1;
            vector<int> nt;
            int cnt = 0;
            for(int i = 0; i < target.size(); i++){
                if(s[i] == '1'){
                    cnt++;
                    a = getLcm(a, target[i]);
                }else{
                    nt.push_back(target[i]);
                }
            }
            if(cnt == 1) continue;
            if(a != 1) nt.push_back(a);
            int n = nt.size();
            int allMask = (1 << n) - 1;
            vector<vector<int>> dp(nums.size(), vector<int>((1 << n), -1));
            ans = min(ans, getAns(nums, 0, 0, allMask, dp, nt));
        }
        if(target.size() == 4){
            vector<int> nt;
            int allMask = (1 << 2) - 1;
            vector<vector<int>> dp1(nums.size(), vector<int>((1 << 2), -1));
            vector<vector<int>> dp2(nums.size(), vector<int>((1 << 2), -1));
            vector<vector<int>> dp3(nums.size(), vector<int>((1 << 2), -1));
            nt = {getLcm(target[0], target[1]), getLcm(target[2], target[3])};
            ans = min(ans, getAns(nums, 0, 0, allMask, dp1, nt));
            allMask = (1 << 2) - 1;
            nt = {getLcm(target[0], target[2]), getLcm(target[1], target[3])};
            ans = min(ans, getAns(nums, 0, 0, allMask, dp2, nt));
            allMask = (1 << 2) - 1;
            nt = {getLcm(target[0], target[3]), getLcm(target[1], target[2])};
            ans = min(ans, getAns(nums, 0, 0, allMask, dp3, nt));
        }
        return ans;
    }
};
