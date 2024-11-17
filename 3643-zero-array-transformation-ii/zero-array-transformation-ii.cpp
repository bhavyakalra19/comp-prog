class Solution {
public:
    void checkLine(vector<int> &line, int val, int st, int en, vector<vector<int>> queries){
        for(int i = st; i <= en; i++){
            line[queries[i][0]] += (val * queries[i][2]);
            line[queries[i][1] + 1] -= (val * queries[i][2]);
        }
    }
    
    bool getAns(vector<int> nums, vector<int> line, int n){
        int s = 0;
        for(int i = 0; i < n; i++){
            s += line[i];
            if((nums[i] -= s) > 0){
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> line(n+1,0);
        if(getAns(nums,line,n)){
            return 0;
        }
        int m = queries.size();
        int prev = -1;
        int st = 0;
        int en = m;
        int ans = INT_MAX;
        
        while(st < en){
            int mid = (st + en)/2;
            if(mid > prev){
                checkLine(line,1,prev+1,mid,queries);
            }else if(mid < prev){
                checkLine(line,-1,mid+1,prev,queries);
            }
            if(getAns(nums,line,n)){
                en = mid;
                ans = min(ans, mid + 1);
            }else{
                st = mid + 1;
            }
            prev = mid;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};