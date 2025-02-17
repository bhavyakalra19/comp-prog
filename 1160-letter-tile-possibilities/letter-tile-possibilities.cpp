class Solution {
public:
    unordered_set<string> st;
    vector<bool> check;
    void getAns(string s, string &tiles, int cnt){
        if(cnt == tiles.size()){
            st.insert(s);
            return;
        }
        getAns(s, tiles, cnt+1);
        for(int i = 0; i < check.size(); i++){
            if(check[i]){
                check[i] = false;
                getAns(s + tiles[i], tiles, cnt + 1);
                check[i] = true;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        check.resize(n,true);
        getAns("", tiles, 0);
        return st.size() - 1;
    }
};