class Solution {
public:
    long long minEnd(int n, int x) {
        long long cur = x;
        long long cal = n - 1;
        vector<int> shifts;
        for(int i = 0; i < 32; i++){
            if(!((1 << i) & x)){
                shifts.push_back(i);
            }
        }
        for(int i = 32; i < 64; i++){
            shifts.push_back(i);
        }

        int i = 0;
        while(cal > 0){
            cur += (cal & 1) << shifts[i];
            i++;
            cal >>= 1;
        }
        return cur;
    }
};