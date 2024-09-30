class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int check = 0;
        for(int i = log2(k); i >= 0; i--){
            if(k > (1LL << i)){
                k -= (1LL << i);
                check += operations[i];
            }
        }
        return 'a' + check % 26;
    }
};