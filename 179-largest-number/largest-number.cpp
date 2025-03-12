class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> check;
        for(auto &a : nums){
            check.push_back(to_string(a));
        }
        sort(check.begin(), check.end(), [](const string &a, const string &b){
            return (a + b) > (b + a);
        });
        string s = "";
        for(auto &a : check){
            s += a;
        }
        if(s[0] == '0') return "0";
        return s;
    }
};