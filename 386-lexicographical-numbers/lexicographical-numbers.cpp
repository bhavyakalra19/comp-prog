class Solution {
public:
    void getAns(int curr, int &n, vector<int> &ans){
        if(curr > n) return;
        ans.push_back(curr);
        for(int i = 0; i < 10; i++){
            getAns(curr * 10 + i, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i < 10; i++){
            getAns(i, n, ans);
        }
        return ans;
    }
};