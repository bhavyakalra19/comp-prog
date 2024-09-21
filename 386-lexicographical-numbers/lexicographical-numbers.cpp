class Solution {
public:
    vector<int> ans;
    void getAns(int n, int check){
        if(check > n){
            return;
        }else if(check == n){
            ans.push_back(n);
            return;
        }else{
            ans.push_back(check);
        }
        for(int i = 0; i < 10; i++){
            getAns(n,check*10 + i);
        }
    }

    vector<int> lexicalOrder(int n) {
        for(int i = 1; i < 10; i++){
            getAns(n,i);
        }
        return ans;
    }
};