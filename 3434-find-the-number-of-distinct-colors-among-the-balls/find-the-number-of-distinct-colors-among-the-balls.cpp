class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> colors;
        unordered_map<int,int> balls;
        int cnt = 0;
        vector<int> ans;
        for(auto q : queries){
            if(balls.find(q[0]) != balls.end()){
                colors[balls[q[0]]]--;
                if(colors[balls[q[0]]] == 0) cnt--;
            }
            colors[q[1]] += 1;
            if(colors[q[1]] == 1){
                cnt++;
            }
            balls[q[0]] = q[1];
            ans.push_back(cnt);
        }
        return ans;
    }
};