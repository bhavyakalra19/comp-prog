class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> check(26,0);
        int count = 0;
        vector<string> ans;
        for(auto w : words2){
            vector<int> curr(26,0);
            for(auto a : w){
                int c = a - 'a';
                curr[c]++;
                if(check[c] == 0){
                    count++;
                }
                if(curr[c] > check[c]){
                    check[c] = curr[c];
                }
            }
        }
cout << count << endl;
        for(auto w : words1){
            vector<int> curr(26,0);
            int cnt = 0;
            for(auto a : w){
                int c = a - 'a';
                curr[c]++;
                if(curr[c] == check[c]){
                    cnt++;
                }
            }
            cout << w << " " << cnt << endl;
            if(cnt == count){
                ans.push_back(w);
            }
        }
        return ans;
    }
};