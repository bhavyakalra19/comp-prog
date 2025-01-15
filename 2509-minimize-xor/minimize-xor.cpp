class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt2 = 0;
        int cnt1 = 0;
        int n1 = num1;
        while(num2 > 0){
            if(num2 & 1){
                cnt2++;
            }
            num2 = num2 >> 1;
        }
        while(n1 > 0){
            if(n1 & 1){
                cnt1++;
            }
            n1 = n1 >> 1;
        }
        if(cnt1 == cnt2){
            return num1;
        }else if(cnt1 > cnt2){
            cnt2 = cnt1 - cnt2;
            for(int i = 0; i < 32; i++){
                if((1 << i) & num1){
                    --cnt2;
                    num1 = num1 ^ (1 << i);
                    if(cnt2 == 0){
                        return num1;
                    }
                }
            }
        }
        cnt2 -= cnt1;
        for(int i = 0; i < 32; i++){
          if(((1 << i) & num1)== 0){
                --cnt2;
                num1 += (1 << i);
                if(cnt2 == 0){
                    break;
                }
            }  
        }
        return num1;
    }
};