class Solution {
public:
    bool getAns(vector<int> quant, int n, int k){
        int ans = 0;
        for(auto q : quant){
            if((q % k) != 0){
                ans += 1;
            }
            ans += (q/k);
            if(ans > n){
                return false;
            }
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1;
        int e = 0;
        for(auto a : quantities){
            e = max(e,a);
        }
        while(s < e){
            int mid = (s + e)/2;
            if(getAns(quantities,n,mid)){
                e = mid;
            }else{
                s = mid + 1;
            }
        }
        return e;
    }
};