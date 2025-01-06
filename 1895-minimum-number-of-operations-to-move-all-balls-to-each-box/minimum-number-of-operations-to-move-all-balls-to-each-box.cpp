class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> check(n);
        int cnt = 0;
        int sum = 0;
        for(int i = n-1; i >= 0; i--){
            check[i] = sum;
            if(boxes[i] == '1'){
                cnt += 1;
            }
            sum += cnt;
        }
        cnt = 0;
        sum = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(sum + check[i]);
            if(boxes[i] == '1'){
                cnt++;
            }
            sum += cnt;
        }
        return ans;
    }
};