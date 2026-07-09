class Solution {
public:
    //union find
    vector<int> check;

    int findFunc(int a){
        if(check[a] == a){
            return a;
        }
        return check[a] = findFunc(check[a]);
    }

    void unionFunc(int a, int b){
        int f1 = findFunc(a);
        int f2 = findFunc(b);
        check[f1] = f2;
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        //find table initialized
        check.resize(n);
        for(int i = 0; i < n; i++){
            check[i] = i;
        }
        vector<bool> ans;
     
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] - nums[i] <= maxDiff){
                unionFunc(i, i+1);
            }
        }

        for(auto &a : queries){
            int f1 = findFunc(a[0]);
            int f2 = findFunc(a[1]);
            if(f1 != f2){
                ans.push_back(false);
            }else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};