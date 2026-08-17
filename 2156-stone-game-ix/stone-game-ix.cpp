class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int one = 0;
        int two = 0;
        int three = 0;
        int n = stones.size();
        for(auto &a: stones){
            int x = a % 3;
            if(x % 3 == 0){
                three++;
            }else if(x == 1){
                one++;
            }else{
                two++;
            }
        }
        if(three % 2 == 0){
            if(one == 0|| two == 0) return false;
        }else{
            if(abs(one - two) <= 2) return false;
        }
        return true;
    }
};


// 1 -> 1 -> 2 -> 1 -> 2

// 2 -> 2 -> 1 
