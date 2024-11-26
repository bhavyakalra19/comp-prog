class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> check(n+1,0);
        for(auto e : edges){
            check[e[1]] += 1;
        }
        int count = 0;
        int ans = - 1;
        for(int i = 0; i < n; i++){
            if(check[i] == 0){
                ans = i;
                if(count == 1){
                    return -1;
                }
                count++;
            }
        }
        return ans;
    }
};