class Solution {
public:
    bool canAliceWin(int n) {
        bool alice_wins = false;
        int curr = 10;
        while(n >= curr){
            n -= curr;
            alice_wins ^= 1;
            curr--;
        }
        return alice_wins;
    }
};