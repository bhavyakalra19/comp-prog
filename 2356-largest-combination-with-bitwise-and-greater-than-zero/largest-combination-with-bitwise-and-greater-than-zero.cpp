class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> check(32,0);
        int ans = 0;
        for(auto a : candidates){
            int i = 0;
            while(a > 0){
                check[i] += a & 1;
                a = a >> 1;
                i++;
            }
        }
        for(auto c : check){
            ans = max(ans,c);
        }
        return ans;
    }
};