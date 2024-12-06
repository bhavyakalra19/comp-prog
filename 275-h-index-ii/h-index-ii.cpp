class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int st = 1;
        int en = n;
        int ans = 0;
        while(st <= en){
            int mid = (en + st)/2;
            if(citations[n - mid] >= mid){
                st = mid + 1;
                ans = mid;
            }else{
                en = mid - 1;
            }
        }
        return ans;
    }
};