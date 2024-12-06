class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int st = 0;
        int en = n - 1;
        int ans = 0;
        while(st <= en){
            int mid = (en + st)/2;
            if(citations[n - mid - 1] >= mid + 1){
                st = mid + 1;
                ans = mid+1;
            }else{
                en = mid - 1;
            }
        }
        return ans;
    }
};