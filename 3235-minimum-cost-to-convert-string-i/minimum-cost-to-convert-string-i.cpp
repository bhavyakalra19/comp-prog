#define INF 1e9

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans = 0;
        vector<vector<int>> dist(26,vector<int>(26,INF));
        for(int i = 0; i < 26; i++){
            dist[i][i] = 0;
        }
        for(int i = 0; i < original.size(); i++){
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'],cost[i]);
        }
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                if(dist[i][k] < INF){
                    for(int j = 0; j < 26; j++){
                        if(dist[k][j] < INF){
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }
        for(int i = 0; i < source.size(); i++){
            int sourceChar = source[i] - 'a';
            int targetChar = target[i] - 'a';
            if (sourceChar != targetChar) {
                if(dist[sourceChar][targetChar] == INF) {
                    return -1;
                }
                ans += dist[sourceChar][targetChar];
            }
        }
        return ans;
    }
};