class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd = 0;
        int even = 0;
        long long sum = 0;
        int mod = (1e9) + 7;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum % 2 == 0){
                even += 1;
                ans += odd;
            }else{
                odd += 1;
                ans += 1 + even;
            }
            ans %= mod;
        }
        return ans;
    }
};