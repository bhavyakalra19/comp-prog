class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        vector<int> rs;
        int ans = 0;
        int s = 0;
        for(auto a : nums){
            if(a == 0){
                ls.push_back(s);
            }else{
                s += a;
            }
        }
        s = 0;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] == 0){
                rs.push_back(s);
            }else{
                s += nums[i];
            }
        }
        reverse(rs.begin(),rs.end());

        for(int i = 0; i < ls.size(); i++){
            if(abs(ls[i] - rs[i]) == 1){
                ans += 1;
            }else if(ls[i] - rs[i] == 0){
                ans += 2;
            }
        }
        return ans;
    }
};

