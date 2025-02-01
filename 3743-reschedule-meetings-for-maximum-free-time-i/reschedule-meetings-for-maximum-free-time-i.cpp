class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> check;
        check.push_back(startTime[0] - 0);
        for(int i = 1; i < n; i++){
            check.push_back(startTime[i] - endTime[i-1]);
        }
        if(n > 1){
            check.push_back(eventTime - endTime[n-1]);
        }
        int ans = 0;
        int sm = 0;
        for(int i = 0; i < check.size(); i++){
            sm += check[i];
            if(i >= k){
                ans = max(ans,sm);
                sm -= check[i-k];
            }
        }
        ans = max(ans,sm);
        return ans;
    }
};