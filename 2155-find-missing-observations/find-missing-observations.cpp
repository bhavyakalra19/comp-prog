class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;
        int check = 0;
        int sz = rolls.size();
        mean *= (sz + n);
        int meanSum = 0;
        for(int i = 0; i < sz; i++){
            meanSum += rolls[i]; 
        }
        if(meanSum > mean){
            return ans;
        }
        meanSum = mean - meanSum;
        if(meanSum < n || meanSum > n*6){
            return ans;
        }
        int a = meanSum / n;
        int b = meanSum % n;
        for(int i = 0; i < n; i++){
            if(b > 0){
                ans.push_back(a + 1);
                b -= 1;
            }else{
                ans.push_back(a);
            }
        }
        return ans;
    }
};