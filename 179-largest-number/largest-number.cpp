class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> check;
        for(auto a : nums){
            check.push_back(to_string(a));
        }
        sort(check.begin(),check.end(), [](const string &a, const string &b){
            return (a + b) > (b + a);
        });

        if(check[0] == "0"){
            return "0";
        }
        string ans = "";
        for(auto a : check){
            ans += a;
        }
        return ans;
    }
};