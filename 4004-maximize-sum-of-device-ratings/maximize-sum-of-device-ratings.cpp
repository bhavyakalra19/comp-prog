class Solution {
public:
    void solveVector(vector<int> &nums, int &m){
        if(nums[1] < nums[0]){
            swap(nums[1], nums[0]);
        }
        int i = 2;
        while(i < m){
            if(nums[i] <= nums[0]){
                nums[1] = nums[0];
                nums[0] = nums[i];
            }else if(nums[i] < nums[1]){
                nums[1] = nums[i];
            }
            i++;
        }
    } 



    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();

        //handle with m == 1
        if(m == 1){
            long long cost = 0;
            for(int i = 0; i < n; i++){
                cost += units[i][0];
            }
            return cost;
        }

        for(int i = 0; i < n; i++){
            solveVector(units[i], m);
        }

        sort(units.begin(), units.end(), [](const vector<int> &a, const vector<int> &b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] > b[1];
        });

        for(int i = 0; i < n; i++){
            if(units[i][0] != units[i][1]){
                if(units[i][0] <= units[n-1][0]){
                    units[n-1][1] = units[n-1][0]; 
                    units[n-1][0] = units[i][0];
                }else{
                    units[n-1][1] = units[i][0];
                }
                units[i][0] = units[i][1];
            }
        }
        long long cost = 0;
        for(int i = 0; i < n; i++){
            cost += units[i][0];
        }
        return cost;
    }
};
