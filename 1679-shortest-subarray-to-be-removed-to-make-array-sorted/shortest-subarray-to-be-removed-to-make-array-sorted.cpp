class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int pr = 1;
        int sf = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] >= arr[i-1]){
                pr++;
            }else{
                break;
            }
        }
        if(pr == n){
            return 0;
        }
        for(int i = n-2; i >= 0; i--){
            if(arr[i] <= arr[i+1]){
                sf++;
            }else{
                break;
            }
        }
        int result = min(n - pr, n - sf);
        int i = 0;
        int j = n - sf;
        while(i < pr && j < n){
            if(arr[i] <= arr[j]){
                result = min(j - i - 1, result);
                i++;
            }else{
                j++;
            }
        }
        return result;
    }
};