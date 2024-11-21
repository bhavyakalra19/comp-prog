class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        priority_queue<int> pq;
        int ans = 0;
        int i = 0;
        int st = startFuel;
        while(st < target){
            while(i < n && stations[i][0] <= st){
                pq.push(stations[i++][1]);
            }
            if(pq.empty() && st < target){
                return -1;
            }
            if(st >= target){
                return ans;
            }
            st += pq.top();
            pq.pop();
            ans += 1;
        }
        return ans;
    }
};