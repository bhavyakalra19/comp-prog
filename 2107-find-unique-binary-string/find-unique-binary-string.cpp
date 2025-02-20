class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<int,bool> mp;
        int n = nums.size();
        int mx = 0;
        string str = "";
        for(auto &s : nums){
            str += '0';
            int num = 0;
            int sm = 1;
            for(int i = n-1; i >= 0; i--){
                if(s[i] == '1'){
                    num += sm;
                }
                sm = sm << 1;
            }
            mx = max(mx, num);
            mp[num] = true;
        }
        int a;
        for(int i = 0; i <= ((1 << n) - 1); i++){
            if(mp.find(i) == mp.end()){
                a = i;
                break;
            }
        }
        int i = 0;
        while(a > 0){
            if(a & 1){
                str[n-i-1] = '1';
            }
            a >>= 1;
            i++;
        }
        return str;
    }
};