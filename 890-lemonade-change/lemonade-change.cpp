class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int a = 0;
        int b = 0;
        for(int i = 0; i < n; i++){
            if(bills[i] == 5){
                a += 1;
            }else if(bills[i] == 10){
                if(a >= 1){
                    a -= 1;
                }else{
                    return false;
                }
                b += 1;
            }else{
                if(a >= 1 && b >= 1){
                    a -= 1;
                    b -= 1;
                }else if(a >= 3){
                    a -= 3;
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};