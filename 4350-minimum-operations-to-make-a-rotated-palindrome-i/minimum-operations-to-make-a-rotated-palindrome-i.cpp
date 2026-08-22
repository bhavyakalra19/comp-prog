class Solution {
public:
    int n;
    void LeftRotate(string &s){
        char temp = s[0];
        for(int i = 0; i < n-1; i++){
            s[i] = s[i+1];
        }
        s[n-1] = temp;
    }

    int getAns(string &s){
        int sm = 0;
        int i = 0;
        int j = n-1;
        while(i < j){
            int x = s[i] - 'a';
            int y = s[j] - 'a';
            if(x < y){
                sm += min(y - x , x - y + 26);
            }else if(x > y){
                sm += min(y - x + 26, x - y);
            }
            i++;
            j--;
        }
        return sm;
    }

    // 0 - 25 + 26 = 1
    // 25 - 0 = 25
    
    int minOperations(string s) {
        n = s.size();
        int mn = getAns(s);
        int rotate = 0;
        if(mn != 0){
            for(int i = 0; i < n-1; i++){
                LeftRotate(s);
                rotate++;
                mn = min(mn, rotate + getAns(s));
            } 
        }
        
        return mn;
    }
};

// left rotate string then start from left point and end point to calculate the differences between them
// also lets say  a .... z

//     we can check a -> z or z -> a which is min