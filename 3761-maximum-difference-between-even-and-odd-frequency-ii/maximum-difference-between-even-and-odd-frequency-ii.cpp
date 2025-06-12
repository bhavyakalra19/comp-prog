class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;
        vector<vector<int>> freq(5, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++){
            for (int d = 0; d < 5; d++){
                freq[d][i + 1] = freq[d][i];
            }
            freq[s[i] - '0'][i + 1]++;
        }
        for(int first = 0; first < 5; first++){
            for(int second = 0; second < 5; second++){
                if(first == second) continue;
                vector<pair<int,int>> arr;
                vector<vector<int>> check(2,vector<int>(2, 1e9));
                int freqA = 0;
                int freqB = 0;
                int prevA = 0;
                int prevB = 0;
                int left = 0;
                for(int i = k - 1; i < n; i++){
                    freqA = freq[first][i+1];
                    freqB = freq[second][i+1];
                    while(i - left + 1 >= k && freqB - prevB >= 2){
                        check[prevA & 1][prevB & 1] = min(check[prevA & 1][prevB & 1], prevA - prevB);
                        prevA = freq[first][left+1];
                        prevB = freq[second][left+1];
                        left++;
                    }
                    ans = max(ans, freqA - freqB - check[1 - (freqA & 1)][freqB & 1]);
                }
            }
        }
        return ans;
    }
};

// eo | oo
// ee | oe
// oe | ee
// oo | eo

// ee 0
// eo 1
// oe 2
// oo 3