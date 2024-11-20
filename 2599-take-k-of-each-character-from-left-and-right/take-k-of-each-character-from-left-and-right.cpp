class Solution {
public:
    int takeCharacters(string s, int k) {
        int check[3] = {0};
        int count  = 0;
        int ans = INT_MAX;
        int j = 0;
        int n = s.size();
        int main = 2 * n;
        if(k == 0){
            return 0;
        }
        for(int i = 0; i < main, j <= n; i++){
            int ct = s[i%n] - 'a';
            check[ct] += 1;
            if(check[ct] == k){
                count++;
            }
            if(j == 0 && count == 3){
                ans = min(ans,i - j + 1);
            }
            while(count == 3){
                if(i >= (n - 1) && j < n){
                    ans = min(ans, i - j + 1);
                }
                int ct = s[j%n] - 'a';
                if(check[ct] == k){
                    break;
                }
                check[ct] -= 1;
                j++;
            }
            if(i == n - 1 && ans == INT_MAX && count < 3){
                return -1;
            }
        }
        return ans;
    }
};