class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> check;
        int prev = 0;
        for(int i = 0; i < n; i++){
            check.push_back(startTime[i] - prev);
            prev = endTime[i];
        }
        check.push_back(eventTime - prev);
        for(auto c : check){
            cout << c << " ";
        }
        cout << endl;
        int i = 0;
        int j = 0;
        int mx = 0;
        int ans = 0;
        while(j < k+1){
            mx += check[j++];
        }
        ans = max(ans, mx);
        while(j < check.size()){
            mx += check[j++];
            mx -= check[i++];
            ans = max(ans, mx);
        }
        return ans;
    }
};