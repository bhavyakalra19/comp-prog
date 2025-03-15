class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int st = 0;
        int i = 0;
        int n = stations.size();
        int ans = 0;
        while(1){
            st += startFuel;
            if(st >= target) return ans;
            while(i < n && stations[i][0] <= st){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) break;
            startFuel = pq.top();
            ans++;
            pq.pop();
        }
        return -1;
    }
};

