class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int mx = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, arr[i]);
            if(mx == i){
                ans += 1;
            }
        }
        return ans;
    }
};