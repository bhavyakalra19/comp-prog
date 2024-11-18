class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans;
        int sum = 0;
        if(k > 0){
            for(int i = 1; i <= k; i++){
                sum += code[i];
            }
            ans.push_back(sum);
            for(int i = 1; i < n; i++){
                sum += code[(k+i)%n];
                sum -= code[i];
                ans.push_back(sum);
            }
        }else if(k < 0){
            for(int i = 0; i < abs(k); i++){
                sum += code[n - i - 1];
            }
            ans.push_back(sum);
            int j = n + k;
            for(int i = 1; i < n; i++){
                sum += code[i - 1];
                sum -= code[j];
                j = (j + 1)%n;
                ans.push_back(sum);
            }
        }else if(k == 0){
            for(int i = 0; i < n; i++){
                ans.push_back(0);
            }
        }
        return ans;
    }
};