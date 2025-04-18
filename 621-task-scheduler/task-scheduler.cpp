class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s = tasks.size();
        vector<int> check(26,0);
        int mx = 0;
        for(int i = 0; i < s; i++){
            int a = tasks[i] - 'A';
            check[a]++;
            mx = max(mx, check[a]);
        }
        int cnt = 0;
        for(int i = 0; i < 26; i++){
            if(check[i] == mx){
                cnt++;
            }
        }
        int ans = (n + 1) * (mx - 1);
        ans += cnt;
        return max(ans, s);
    }
};