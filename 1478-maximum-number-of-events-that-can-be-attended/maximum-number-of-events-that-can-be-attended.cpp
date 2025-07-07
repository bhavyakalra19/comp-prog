class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        int time = 0;
        int ans = 0;
        while(!pq.empty() || i < n){
            if(pq.empty() && time < events[i][0]){
                time = events[i][0];
            }
            while(i < n && events[i][0] == time){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty()){
                ans++;
                pq.pop();
            }
            time += 1;
            while(!pq.empty() && pq.top() < time){
                pq.pop();
            }
        }
        return ans;
    }
};