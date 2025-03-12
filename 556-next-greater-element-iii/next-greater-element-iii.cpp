class Solution {
public:
    int nextGreaterElement(int num) {
        string s = to_string(num);
        int n = s.size();
        int sm = 9;
        int j = n;
        for(int i = n-1; i > 0; i--){
            if(s[i] > s[i-1]){
                j = n-1;
                while(s[j] <= s[i-1]){
                    j--;
                }
                swap(s[i-1], s[j]);
                j = i;
                break;
            }
        }
        if(j == n) return -1;
        sort(s.begin() + j, s.end());
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans *= 10;
            ans += (s[i] - '0');
        }
        return ans > INT_MAX ? -1 : ans;
    }
};

