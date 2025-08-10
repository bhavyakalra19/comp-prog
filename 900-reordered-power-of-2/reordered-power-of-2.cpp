class Solution {
public:

    int countDigits(int a){
        int cnt = 0;
        while(a > 0){
            a /= 10;
            cnt++;
        }
        return cnt;
    }

    bool checkNumber(int a, unordered_map<int,int> &mp){
        unordered_map<int,int> check;
        while(a > 0){
            int last = a % 10;
            check[last]++;
            a /= 10;
        }
        for(auto &m : mp){
            if(m.second != check[m.first]) return false;
        }
        return true;
    }

    bool reorderedPowerOf2(int n) {
        int a = 1;
        int check = n;
        int cnt = 0;
        unordered_map<int,int> mp; 
        while(check > 0){
            int last = check % 10;
            mp[last]++;
            check /= 10;
            cnt++;
        }
        n = min(1LL * n * 10, 1LL * 1000000000);
        while(a <= n){
            if(countDigits(a) == cnt && checkNumber(a, mp)){
                return true;
            }
            a <<= 1;
        }
        return false;
    }
};