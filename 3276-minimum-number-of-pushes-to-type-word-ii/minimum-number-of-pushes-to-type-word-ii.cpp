class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int key = 0;
        vector<int> keypad(26,0);
        for(int i = 0; i < n; i++){
            keypad[word[i] - 'a'] += 1;
        }
        sort(keypad.begin(),keypad.end());
        for(int i = 25; i >= 0; i--){
            if(keypad[i] == 0){
                break;
            }
            ans += keypad[i] * ((key/8) + 1);
            key += 1;
        }
        return ans;
    }
};