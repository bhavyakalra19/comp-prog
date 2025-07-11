class Solution {
public:
    int mostBooked(int m, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        int i = 0;
        long long time = 0;
        priority_queue<int, vector<int>, greater<int>> token;
        for(int i = 0; i < m; i++){
            token.push(i);
        }
        vector<int> token_count(m, 0);
        while(i < n){
            if(pq.empty() && time < meetings[i][0]){
                time = meetings[i][0];
            }
            while(i < n && (!token.empty() && time >= meetings[i][0])){
                int curr = token.top();
                pq.push({time + meetings[i][1] - meetings[i][0] - 1, curr});
                token_count[curr] += 1;
                token.pop();
                i++;
            }
            if(token.empty()){
                time = pq.top().first;
            }
            while(!pq.empty() && pq.top().first <= time){
                token.push(pq.top().second);
                pq.pop();
            }
            time++;
        }
        int cnt = 0;
        int num = 0;
        for(int i = 0; i < m; i++){
            if(token_count[i] > cnt){
                cnt = token_count[i];
                num = i;
            }
        }
        return num;
    }
};
