class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> check;
        for(int i = 0; i < n; i++){
            check.push_back(to_string(nums[i]));
        }
        sort(check.begin(), check.end(), [](const string &a, const string &b){
            return a + b > b + a;
        });
        string ans = "";
        int i = 0;
        while(i < n && check[i] == "0") i++;
        while(i < n) ans += check[i++];
        return ans == "" ? "0" : ans;
    }
};