class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        int lI;
        int rD;
        int lD;
        int rI;
        for(int i = 1; i < n-1; i++){
            lI = 0;
            rD = 0;
            lD = 0;
            rI = 0;
            for(int j = i-1; j >= 0; j--){
                //Decreasing
                if(rating[j] < rating[i]){
                    lD += 1;
                }else{
                    lI += 1;
                }
            }

            for(int j = i+1; j < n; j++){
                if(rating[j] > rating[i]){
                    rI += 1;
                }else{
                    rD += 1;
                }
            }
            ans += lI*rD;
            ans += lD*rI;
        }
        return ans;
    }
};