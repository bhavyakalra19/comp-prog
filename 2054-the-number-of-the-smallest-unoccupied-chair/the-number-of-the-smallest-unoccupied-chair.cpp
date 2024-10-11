class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        unordered_map<int, vector<int>> mp;
        int check = times[targetFriend][0];
        int time = 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> timePq;

        for(int i = 0; i < n; i++){
            pq.push(i);
            timePq.push({times[i][0], times[i][1]});
        }
        while(time < check){
            for(auto a : mp[time]){
                pq.push(a);
            }
            
            auto it = timePq.top();
            if(it.first == time){
                timePq.pop();
                mp[it.second].push_back(pq.top());
                pq.pop();
            }
            time++;
        }
        for(auto a : mp[time]){
            pq.push(a);
        }
        return pq.top();
    }
};