class Solution {
public:
    int maximumSwap(int num) {
        int target  = num;
        if(num < 9){
            return num;
        }
        vector<int> check;
        vector<int> cmp;
        while(num > 0){
            check.push_back(num%10);
            cmp.push_back(num%10);
            num /= 10;
        }
        reverse(check.begin(), check.end());
        sort(cmp.begin(), cmp.end(), greater<int>());
        int n = check.size();
        for(int i = 0; i < n; i++){
            if(cmp[i] > check[i]){
                int idx = n - i - 1;
                for(int j = n - 1; j > i; j--){
                    if(check[j] == cmp[i]){
                        cout << check[i] << " " << cmp[i] << endl;
                        int b = cmp[i] - check[i];
                        target = target + (b)*(pow(10,idx)) - b*(pow(10,n - j - 1));
                        return target;
                    }
                }
            }
        }
        return target;
    }
};