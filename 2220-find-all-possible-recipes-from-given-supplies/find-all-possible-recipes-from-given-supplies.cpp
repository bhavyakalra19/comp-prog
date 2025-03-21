class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st;
        unordered_map<string, int> inDegree;
        unordered_map<string, vector<string>> adj;
        queue<string> q;
        vector<string> ans;
        int n = recipes.size();
        for(int i = 0; i < n; i++){
            for(auto &a : ingredients[i]){
                inDegree[recipes[i]]++;
                adj[a].push_back(recipes[i]);
            }
        }

        for(auto &a : supplies){
            st.insert(a);
            q.push(a);
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(auto &a : adj[it]){
                inDegree[a]--;
                if(inDegree[a] == 0){
                    q.push(a);
                    if(st.find(a) == st.end()) ans.push_back(a);
                }
            }
        }
        return ans;
    }
};
