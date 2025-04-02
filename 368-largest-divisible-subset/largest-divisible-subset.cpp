class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> check(n);
        vector<int> path(n);
        int ans = 0;
        int mx = 0;
        check[0] = 1;
        path[0] = 0;
        for(int i = 1; i < n; i++){
            int curr = 0;
            int currIdx = i;
            for(int j = 0; j < i; j++){
                if((nums[i] % nums[j] == 0) && check[j] > curr){
                    curr = check[j];
                    currIdx = j;
                }
            }
            path[i] = currIdx;
            check[i] = curr + 1;
            if(check[i] > ans){
                ans = check[i];
                mx = i;
            }
        }
        vector<int> result;
        while(mx != path[mx]){
            result.push_back(nums[mx]);
            mx = path[mx];
        }
        result.push_back(nums[mx]);
        reverse(result.begin(), result.end());
        return result;
    }
};