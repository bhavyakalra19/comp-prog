class Solution {
public:
    void createArray(string s, vector<long long> &nums){
        long long curr = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*'){
                curr = max(0LL, curr - 1);
            }else if(s[i] == '#'){
                curr = 2 * curr;
            }else if(s[i] != '%'){
                curr += 1;
            }
            nums[i] = curr;
        }
    }


    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> nums(n);
        createArray(s, nums);
        if(k >= nums[n-1]) return '.';

        for(int i = n-1; i >= 0; i--){
            if(s[i] == '*'){
                continue;
            }else if(s[i] == '#'){
                long long len = nums[i] / 2;
                if(k >= len) k = k - len;
            }else if(s[i] == '%'){
                k = nums[i] - k - 1;
            }else{
                if(k == (nums[i] - 1)){
                    return s[i];
                }
            }
        }
        return s[0];
    }
};