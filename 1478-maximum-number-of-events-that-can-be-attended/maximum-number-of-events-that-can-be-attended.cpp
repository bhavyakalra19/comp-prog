class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        priority_queue<int ,vector<int>, greater<int>> pq;
        int ans = 0;
        int j = 0;
        sort(events.begin(),events.end());
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx,events[i][1]);
        }
        for(int i = 1; i <= mx; i++){
            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }
            while(j < n && events[j][0] == i){
                pq.push(events[j][1]);
                j++;
            }
            if(!pq.empty()){
                pq.pop();
                ans += 1;
            }
        }
        return ans;
    }
};