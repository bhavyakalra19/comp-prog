class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int ans = 0;
        int mx = 0;
        for(auto e : events){
            int st = e[0];
            int en = e[1];
            int vl = e[2];
            while(!pq.empty() && pq.top().first < st){
                mx = max(mx, pq.top().second);
                pq.pop();
            }
            ans = max(ans, mx + vl);
            pq.push({en,vl});
        }
        return ans;
    }
};