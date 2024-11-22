class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1 = INT_MIN;
        int s1 = 0;
        int b2 = INT_MIN;
        int s2 = 0;
        for(auto p : prices){
            b1 = max(b1,-p);
            s1 = max(s1,p + b1);
            b2 = max(b2,-p + s1);
            s2 = max(s2,p + b2);
        }
        return s2;
    }
};