class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int prev = 0;
        int i = 0;
        int ans = 0;
        int j = 0;
        int fn = fruits[0];
        int sn = -1;
        while(i < n){
            if(fruits[i] != fn && fruits[i] != sn){
                if(sn != -1){
                    ans = max(ans, i - j);
                    j = prev;
                    fn = fruits[j];
                }
                sn = fruits[i];
            }
            if(i > 0 && fruits[i] != fruits[i-1]){
                prev = i;
            }
            i++;
        }
        ans = max(ans, n - j);
        return ans;
    }
};

