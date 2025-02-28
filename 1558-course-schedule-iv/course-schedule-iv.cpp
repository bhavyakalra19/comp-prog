class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> gp(n);
        vector<unordered_set<int>> check(n);
        vector<int> degree(n,0);
        vector<bool> ans;
        for(auto p : prerequisites){
            gp[p[0]].push_back(p[1]);
            degree[p[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(auto g : gp[it]){
                --degree[g];
                check[g].insert(it);
                for(auto c : check[it]){
                    check[g].insert(c);
                }
                if(degree[g] == 0){
                    q.push(g);
                }
            }
        }

        for(auto q : queries){
            if(check[q[1]].find(q[0]) != check[q[1]].end()){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
