class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int N = 0;
        int S = 0;
        int E = 0;
        int W = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'N'){
                N++;
            }else if(s[i] == 'S'){
                S++;
            }else if(s[i] == 'E'){
                E++;
            }else if(s[i] == 'W'){
                W++;
            }
            int xMin = min(N, S);
            int xMax = max(N, S);
            int yMin = min(W, E);
            int yMax = max(W, E);
            ans = max(ans, xMax + yMax - xMin - yMin + (2 * min(k, xMin + yMin)));
        }
        return ans;
    }
    
};