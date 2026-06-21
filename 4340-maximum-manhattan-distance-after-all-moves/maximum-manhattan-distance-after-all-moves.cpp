class Solution {
public:
    int maxDistance(string moves) {
        int a = 0;
        int b = 0;
        int c = 0;
        for(auto &x : moves){
            if(x == 'U'){
                a++;
            }else if(x == 'D'){
                a--;
            }else if(x == 'L'){
                b--;
            }else if(x == 'R'){
                b++;
            }else{
                c++;
            }
        }
        // cout << a << " " << b << " " << c << endl;
        return abs(a) + abs(b) + c;
    }
};