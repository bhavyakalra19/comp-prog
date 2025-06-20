class Solution {
public:
    int maxDistance(string str, int k) {
        int n = 0;
        int w = 0;
        int e = 0;
        int s = 0;
        int ans = 0;
        int x = 0;
        int y = 0;
        for(auto a : str){
            if(a == 'N'){
                n++;
                y++;
            }else if(a == 'S'){
                s++;
                y--;
            }else if(a == 'W'){
                w++;
                x++;
            }else{
                e++;
                x--;
            }
            if(n > s){
                if(e > w){
                    ans = max(ans, abs(x) + abs(y) + 2 * min(k,w + s));
                }else{
                    ans = max(ans, abs(x) + abs(y) + 2 * min(k,e + s));
                }
            }else{
                if(e > w){
                    ans = max(ans, abs(x) + abs(y) + 2 * min(k, n + w));
                }else{
                    ans = max(ans, abs(x) + abs(y) + 2 * min(k, n + e));
                }
            }
        }
        return ans;
    }
};