class Solution {
public:
    bool checkEqual(vector<int> &nums, int k){
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i += 2){
            ans += nums[i+1] - nums[i];
        }
        return k >= ans;
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        int ps = 0;
        int ns = 0;
         for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                pos.push_back(i);
                ps++;
            }else{
                neg.push_back(i);
                ns++;
            }
        }
        if(ps == n || ns == n) return true;
        if((ps % 2 != 0) && (ns % 2 != 0)) return false;
        if((ps % 2 == 0) && (ns % 2 == 0)){
            return checkEqual(neg, k) | checkEqual(pos, k);
        }else if(ps % 2 == 0){
            return checkEqual(pos, k);
        }
        return checkEqual(neg, k);
    }
};
