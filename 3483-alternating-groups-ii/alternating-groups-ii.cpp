class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < n){
            if(j == i || colors[(j)%n] != colors[(j-1)%n]){
                j++;
            }else{
                i = j;
            }
            if(j - i == k){
                ans += 1;
                i += 1;
            }
        }
        return ans;
    }
};