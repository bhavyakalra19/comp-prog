class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        int m = word2.size();
        int j = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            prefix[i] = cnt;
            if(j < m && word1[i] == word2[j]){
                j++;
                cnt++;
            }
        }
        j = m-1;
        cnt = 0;
        for(int i = n-1; i >= 0; i--){
            suffix[i] = cnt;
            if(j >= 0 && word1[i] == word2[j]){
                j--;
                cnt++;
            }
        }
        bool check = true;
        j = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(word1[i] == word2[j]){
                j++;
                ans.push_back(i);
                if(j == m) break;
            }else if ((suffix[i] + prefix[i]) >= (m-1) && check){
                j++;
                ans.push_back(i);
                check = false;
            }
        }
        if(ans.size() != m){
            return {};
        }
        return ans;
    }
};
// cvbabac
// cabac

// c v b c
// 0 1 2 2
// 2 1 1 0

