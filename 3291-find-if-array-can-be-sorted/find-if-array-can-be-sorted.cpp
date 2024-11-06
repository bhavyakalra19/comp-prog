class Solution {
public:
    int getSet(int num){
        int ans = 0;
        while(num > 0){
            ans += (num & 1);
            num = num >> 1;
        }
        return ans;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> check;
        vector<pair<int,int>> ans;
        for(int i = 0; i < n; i++){
            check.push_back(getSet(nums[i]));
        }
        int i = 0;
        while(i < n){
            int s = i;
            int mn = nums[i];
            int mx = nums[i];
            while(i < n && check[i] == check[s]){
                mn = min(mn, nums[i]);
                mx = max(mx, nums[i]);
                i++;
            }
            ans.push_back({mn,mx});
        }
        for(int i = 1; i < ans.size(); i++){
            if(ans[i].first < ans[i-1].second){
                return false;
            }
        }
        return true;
    }
};