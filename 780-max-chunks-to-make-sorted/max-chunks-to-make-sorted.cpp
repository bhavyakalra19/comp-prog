class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int mx = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            mx = max(arr[i],mx);
            if(mx == i){
                ans += 1;
            }
        }
        return ans;
    }
};