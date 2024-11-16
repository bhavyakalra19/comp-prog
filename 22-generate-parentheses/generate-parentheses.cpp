class Solution {
public:
    void getAns(string s, int p, int c, vector<string> &ans){
        if(p == 0 && c == 0){
            ans.push_back(s);
            return;
        }
        if(p){
            getAns(s + '(', p-1,c+1,ans);
        }
        if(c){
            getAns(s + ')', p, c-1,ans);
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getAns("",n,0,ans);
        return ans;
    }
};