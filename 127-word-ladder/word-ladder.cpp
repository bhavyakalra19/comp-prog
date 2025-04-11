class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto &w : wordList){
            st.insert(w);
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
                if(it == endWord) return ans;
                for(int i = 0; i < n; i++){
                    string temp = it;
                    for(char a = 'a'; a <= 'z'; a++){
                        temp[i] = a;
                        if(st.find(temp) != st.end()){
                            st.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};