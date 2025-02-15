class Solution {
public:
    void getAns(vector<int> &arr, int idx, int total, bool &ans, int &check){
        if(ans) return;
        if(idx < 0){
            if(total == check){
                ans = true;
            }
            return;
        }
        int sm = 0;
        for(int i = idx; i >= 0; i--){
            sm = sm * 10;
            sm += arr[i];
            getAns(arr, i - 1, total + sm, ans, check);
        }
    }

    bool checkNum(int num, int check){
        vector<int> arr;
        while(num > 0){
            arr.push_back(num % 10);
            num /= 10;
        }
        bool ans = false;
        getAns(arr,arr.size() - 1, 0, ans, check);
        return ans;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(checkNum(i*i, i)) {
                ans += i*i;
            }
        }
        return ans;
    }
};