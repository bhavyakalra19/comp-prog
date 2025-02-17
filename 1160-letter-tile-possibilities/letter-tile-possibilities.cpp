class Solution {
public:
    void getAns(string s, unordered_set<string> &st, vector<bool> &check, string &tiles, int cnt){
        if(cnt == tiles.size()){
            st.insert(s);
            return;
        }
        getAns(s, st, check, tiles, cnt+1);
        for(int i = 0; i < check.size(); i++){
            if(check[i]){
                check[i] = false;
                getAns(s + tiles[i], st, check, tiles, cnt + 1);
                check[i] = true;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> check(n,true);
        unordered_set<string> st;
        getAns("", st, check, tiles, 0);
        return st.size() - 1;
    }
};