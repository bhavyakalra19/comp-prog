class Solution {
public:

    void getAns(int n, int m, vector<string> &ans, string s){
        if(n == 0 && m == 0){   
            ans.push_back(s);
        }
        if(n > 0){
            getAns(n-1, m+1, ans, s + "(");
        }
        if(m > 0){
            getAns(n, m-1, ans, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getAns(n, 0, ans, "");
        return ans;
    }
};