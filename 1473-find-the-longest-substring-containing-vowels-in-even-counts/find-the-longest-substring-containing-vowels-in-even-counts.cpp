class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> mapy(32,-2);
        mapy[0] = -1;
        int mask = 0;
        int n = s.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                mask ^= 1;
            }else if(s[i] == 'e'){
                mask ^= 2;
            }else if(s[i] == 'i'){
                mask ^= 4;
            }else if(s[i] == 'o'){
                mask ^= 8;
            }else if(s[i] == 'u'){
                mask ^= 16;
            }
            int prev = mapy[mask];
            if(prev == -2){
                mapy[mask] = i;
            }else{
                maxLen = max(maxLen, i - prev);
            }
        }
        return maxLen;
    }
};