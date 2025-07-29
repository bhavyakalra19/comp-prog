class Solution {
public:
    int updateVal(vector<int> &check, int num, bool add){
        int a = 0;
        while(num > 0){
            if(num & 1){
                if(add){
                    check[a]++;
                }else{
                    check[a]--;
                }
            }
            num >>= 1;
            a++;
        }
        int curr = 0;
        for(int i = 0; i < 32; i++){
            if(check[i]){
                curr += (1 << i);
            }
        }
        return curr;
    }

    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        vector<int> check(32, 0);
        vector<int> check2(32, 0);
        for(int i = 0; i < n; i++){
            mx = updateVal(check, nums[i], true);
        }
        vector<int> ans;
        int j = 0;
        int curr = 0;
        for(int i = 0; i < n; i++){
            if(j < i) j = i;
            while(j < n && curr != mx){
                curr = updateVal(check2, nums[j], true);
                j++;
            }
            ans.push_back(j - i == 0 ? 1 : j - i);
            mx = updateVal(check, nums[i], false);
            curr = updateVal(check2, nums[i], false);
        }
        return ans;
    }
};