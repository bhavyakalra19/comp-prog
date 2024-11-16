class Solution {
public:
    vector<string> ans;

    void getAns(string s, int p, int c){
        if(p == 0 && c == 0){
            ans.push_back(s);
            return;
        }
        if(p){
            getAns(s + '(', p-1,c+1);
        }
        if(c){
            getAns(s + ')', p, c-1);
        }
    }


    vector<string> generateParenthesis(int n) {
        getAns("",n,0);
        return ans;
    }
};