class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int mn = fruits[0][0];
        int mx = max(startPos,min(startPos + k, fruits[n-1][0]));
        int cost = 0;
        int ans = 0;
        int j = 0;
        int jSt = 0;
        vector<int> rightCost(k + 1, 0);
        //check for fruits which are reachable from starPos in left side
        while(j < n && fruits[j][0] < startPos - k){
            j++;
        }
        jSt = j;
        //calculating total cost from left most reachable point to startPos inclusive
        while(j < n && fruits[j][0] <= startPos){
            cost += fruits[j++][1];
        }
        //calculating prefix Sum for right most Reachable Part
        if(j < n){
            for(int i = startPos + 1; i <= startPos + k; i++){
                int point = i - startPos;
                if(j < n && (fruits[j][0] == i)){
                    rightCost[point] += fruits[j][1];
                    j++;
                }
                rightCost[point] += rightCost[point - 1];
            }
        }
        j = jSt;
        for(int i = startPos - k; i <= startPos; i++){
            int left = startPos - i;
            int right = (k - left) / 2;
            int currCost = cost + rightCost[right];
            ans = max(ans, currCost);
            if(left * 2 <= k){
                int secondRight = k - left * 2;
                int newCost = cost + rightCost[secondRight];
                ans = max(ans, newCost);
            }
            if(j < n && fruits[j][0] == i){
                cost -= fruits[j++][1];
            }
        }
        return ans;
    }
};


