class Solution {
public:

    bool maxSubstringLength(string s, int k) {
        vector<vector<int>> check(26,vector<int>(2,-1));
        vector<vector<int>> gp;
        int n = s.size();
        for(int i = 0; i < n; i++){
            int a = s[i] - 'a';
            if(check[a][0] == -1){
                check[a][0] = i;
            }
            check[a][1] = i;
        }
        for(int i = 0; i < n; i++){
            int a = s[i] - 'a';
            if(check[a][0] != i){
                continue;
            }
            int far = check[a][1];
            int curr = check[a][0];
            int isValid = true;
            while(curr <= far){
                if(check[s[curr] - 'a'][0] < check[a][0]){
                    isValid = false;
                    break;
                }
                far = max(far, check[s[curr] - 'a'][1]);
                curr++;
            }
            if(isValid && far - i + 1 != n) gp.push_back({i,far});
        }
        sort(gp.begin(), gp.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int cnt = 0;
        int prev = -1;
        for(auto g : gp){
            if(g[0] > prev){
                prev = g[1];
                cnt++;
            }
        }
        return cnt >= k;
    }
};