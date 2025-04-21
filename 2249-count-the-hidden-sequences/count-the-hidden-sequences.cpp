class Solution {
public:
    int numberOfArrays(vector<int>& differences, long long lower, long long upper) {
        long long mn = 0;
        long long mx = 0;
        long long sum = 0;
        int n = differences.size();
        for(int i = 0; i < n; i++){
            sum += 1LL * differences[i];
            mn = min(mn, sum);
            mx = max(mx, sum); 
        }
        long long lowLimit = max(lower, lower - mn);
        long long upperLimit = min(upper, upper - mx);
        if(upperLimit < lowLimit) return 0;
        return upperLimit - lowLimit + 1;
    }
};


