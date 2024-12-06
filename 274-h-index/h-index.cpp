class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> check(n+1,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(citations[i] <= n){
                check[citations[i]] += 1;
            }
        }
        int mx = n;
        for(int i = 0; i <= n; i++){
            if(mx < i){
                break;
            }
            ans = max(ans,i);
            mx -= check[i];
        }
        return ans;
    }
};