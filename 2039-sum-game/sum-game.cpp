class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sm1 = 0;
        int sm2 = 0;
        int left = 0;
        int right = 0;
        for(int i = 0; i < n; i++){
            int x = num[i] == '?' ? -1 : num[i] - '0';
            if(i < n/2){
                if(x == -1){
                    left++;
                }else{
                    sm1 += x;
                }
            }else{
                if(x == -1){
                    right++;
                }else{
                    sm2 += x;
                }
            }
        }
        if((right + left) % 2 != 0) return true;
        return (sm1 - sm2) * 2 != (right - left) * 9;
    }
};

// make one side heavier and other side lower


// alice can force max diff to 9 on each side if there are (extra records on either side / 2) so differece should be eqaul to (extra records on either side / 2) * 9

//  1 -> 3
//  1 -> 1
//  0 -> 2


//  5 -> 6

//  1 -> 5 -> heavy or small 
//  2 -> 4
//  3 -> 3
//  4 -> 2
//  5 -> 1
//  6 -> 0