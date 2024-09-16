class Solution {
public:
    int getAns(string time){
        return time[0] * 10 + time[1];
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int n = timePoints.size();
        int ans = INT_MAX;
        for(int i = 1; i < n; i++){
            int a = getAns(timePoints[i].substr(0,2)) * 60 + getAns(timePoints[i].substr(3));
            int b = getAns(timePoints[i-1].substr(0,2)) * 60 + getAns(timePoints[i-1].substr(3));
            ans = min(ans,a-b);
        }
        int a = (getAns(timePoints[0].substr(0,2)) * 60 + 24*60) + getAns(timePoints[0].substr(3));
        int b = getAns(timePoints[n-1].substr(0,2)) * 60 + getAns(timePoints[n-1].substr(3));
        ans = min(ans,a-b);
        return ans;
    }
};