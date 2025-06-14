class Solution {
public:
    int maxDifference(string s, int k) {
        int n = s.size();
        vector<vector<int>> freq(n+1, vector<int>(5,0));

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 5; j++){
                freq[i][j] = freq[i-1][j];
            }
            int a = s[i-1] - '0';
            freq[i][a]++;
        }
        int ans = INT_MIN;
        for(int first = 0; first < 5; first++){
            for(int second = 0; second < 5; second++){
                if(first == second) continue;
                int last = 0;
                int prevA = 0;
                int prevB = 0;
                int freqA = 0;
                int freqB = 0;
                vector<vector<int>> parity(2,vector<int>(2,1e9));
                for(int i = k-1; i < n; i++){
                    freqA = freq[i+1][first];
                    freqB = freq[i+1][second];
                    while(i - last + 1 >= k && freqB - prevB >= 2){
                        parity[prevA & 1][prevB & 1] = min(parity[prevA & 1][prevB & 1], prevA - prevB);
                        last++;
                        prevA = freq[last][first];
                        prevB = freq[last][second];
                    }
                    ans = max(ans, freqA - freqB - parity[1 - (freqA & 1)][freqB & 1]);
                }
            }
        }
        return ans;
    }
};


// (freqA - freqB) - min((prevA - prevB))

// e & 1 = 0 

// o & 1 = 1

// e e = 0 0
// e o = 0 1
// o e = 1 0
// o o = 1 1

// e e == o e
// e o == o o
// o o == e o
// o e == e e
// count a = freq[i+1];
// count b = freq[i+1];

// prevB = freq[last];
// count b = freq