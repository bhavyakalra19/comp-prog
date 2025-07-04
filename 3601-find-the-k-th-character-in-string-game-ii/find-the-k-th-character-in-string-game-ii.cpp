class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long change = 0;
        for(int i = log2(k); i >= 0; i--){
            long long curr = 1LL << i;
            if(k > curr){
                if(operations[i] == 1){
                    change++;
                }
                k -= curr;
            }
            curr >>= 1;
        }
        int a = change % 26;
        return a + 'a';
    }
};

