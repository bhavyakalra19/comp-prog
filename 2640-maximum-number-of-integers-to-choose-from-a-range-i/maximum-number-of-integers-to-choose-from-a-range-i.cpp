class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> check(n+1,0);
        for(auto b : banned){
            if(b <= n){
                check[b] = 1;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(maxSum < i){
                break;
            }
            if(check[i] == 0){
                cnt++;
                maxSum -= i;
            }
        }
        return cnt;
    }
};