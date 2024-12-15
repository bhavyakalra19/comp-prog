class Solution {
public:
    double gain(double a, double b){
        return ((a + 1) / (b + 1)) - (a/b);
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(auto c : classes){
            pq.push({gain(c[0],c[1]), {c[0],c[1]}});
        }
        while(extraStudents-- > 0){
            auto it = pq.top();
            pq.pop();
            int u = it.second.first + 1;
            int v = it.second.second + 1;
            pq.push({gain(u,v), {u,v}});
        }
        double ans = 0;
        while(!pq.empty()){
            ans += (double) pq.top().second.first / (double) pq.top().second.second;
            pq.pop();
        }
        return ans / classes.size();
    }
};