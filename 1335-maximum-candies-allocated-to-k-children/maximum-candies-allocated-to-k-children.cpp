class Solution {
public:
    bool getAns(vector<int> candies, long long &k, int mx){
        if(mx == 0) return true;
        long long check = 0;
        int i = 0;
        int n = candies.size();
        while(i < n && check < k){
            if(candies[i] >= mx){
                check += candies[i] / mx;
                candies[i] %= mx;
            }
            i++;
        }
        return check >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int st = 0;
        int en = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while(st <= en){
            int mid = (en - st)/2 + st;
            if(getAns(candies, k, mid)){
                ans = mid;
                st = mid + 1;
            }else{
                en = mid - 1;
            }
        }
        return ans;
    }
};