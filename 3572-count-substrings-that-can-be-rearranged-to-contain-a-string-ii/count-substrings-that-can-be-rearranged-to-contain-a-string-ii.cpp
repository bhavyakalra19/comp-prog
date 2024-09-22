class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> check(26,0);
        for(int i = 0; i < word2.size(); i++){
            check[word2[i] - 'a'] += 1;
        }
        int n = word1.size();
        long long ans = 0;
        vector<int> slide(26,0);
        int start = 0;
        int k = word2.size();
        for(int i = 0; i < n; i++){
            char curr = word1[i];
            if(check[curr - 'a'] > 0){
                if(slide[curr - 'a'] < check[curr - 'a']){
                    k--;
                }
            } 
            slide[curr - 'a']++;
            while(k == 0){
                ans += n - i;
                char pre = word1[start];
                slide[pre - 'a']--;
                if(check[pre - 'a'] > 0 && slide[pre - 'a'] < check[pre - 'a']){
                    k++;
                }
                start++;
            }
        }
        return ans;
    }
};