class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> st;
        unordered_map<string, bool> vis;
        for(auto &a : wordList){
            st[a] = true;
        }
        int n = beginWord.size();
        queue<string> q;
        q.push(beginWord);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            ans++;
            while(size--){
                auto it = q.front();
                q.pop();
                vis[it] = true;
                string mn = it;
                for(int i = 0; i < n; i++){
                    for(char a = 'a'; a <= 'z'; a++){
                        it[i] = a;
                        if(st.find(it) != st.end() && vis.find(it) == vis.end()){
                            if(it == endWord) return ans+1;
                            q.push(it);
                        }
                    }
                    it = mn;
                }
            }
        }
        return 0;
    }
};