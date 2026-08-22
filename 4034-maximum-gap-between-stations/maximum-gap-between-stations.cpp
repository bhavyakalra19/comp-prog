class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();
        vector<int> check(n);
        int i = n-1;
        for(int j = m-1; j >= 0; j--){
            if(i >= 0 && station[j] == skill[i]){
                check[i] = j;
                i--;
            }
        }
        i = 0;
        int mx = 0;
        for(int j = 0; j < m; j++){
            if(i < n-1 && skill[i] == station[j]){
                if(i + 1 < n){
                    mx = max(check[i+1] - j, mx);
                }
                i++;
            }
        }
        return mx;
    }
};

// vector<vector<int>> check(26);
//using prefix check and suffix check we can find first and last occurence of each index of skill