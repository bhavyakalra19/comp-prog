class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> check(26,0);
        int k = word2.size();
        for(int i = 0; i < k; i++){
            check[word2[i] - 'a'] += 1;
        }
        int start = 0;
        long long ans = 0;
        vector<int> slide(26,0);
        int n = word1.size();
        for(int i = 0; i < n; i++){
            int a = word1[i] - 'a';
            if(check[a] > 0){
                if(slide[a] < check[a]){
                    k--;
                }
            }
            slide[a]++;
            while(k == 0){
                ans += n - i;
                int c = word1[start] - 'a';
                slide[c]--;
                if(check[c] > 0){
                    if(slide[c] < check[c]){
                        k++;
                    }
                }
                start++;
            }
        }
        return ans;
    }
};