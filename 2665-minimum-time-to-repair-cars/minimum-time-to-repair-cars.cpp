class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long st = 1;
        long long en = LONG_MAX - 1;
        long long cnt = 0;
        while(st <= en){
            long long mid = st + (en - st)/2;
            int i = 0;
            long long ans = 0;
            while(i < n){
                long long a = floor(mid / ranks[i]);
                ans += floor(sqrt(a));
                i++;
            }
            if(ans >= cars){
                cnt = mid;
                en = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return cnt;
    }
};