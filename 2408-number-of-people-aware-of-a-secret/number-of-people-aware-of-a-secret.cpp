class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        long long cnt = 0;
        vector<long long> check(n+forget+1, 0);
        vector<long long> neg(n+forget+1, 0);
        long long knows = 1;
        check[1 + delay] = 1;
        neg[1 + forget] = -1;
        for(int i = 2; i <= n; i++){
            cnt = (cnt + check[i] + neg[i] + mod) % mod;
            knows = (knows + cnt + neg[i] + mod) % mod;
            if(cnt > 0){
                check[i + delay] = (check[i + delay] + cnt) % mod;
                neg[i + forget] = (neg[i + forget] - cnt + mod) % mod;
            }
            // cout << cnt << " " << knows << endl;
        }
        return knows;
    }
};



// 1 2 3 4 5 6 7 8

//     1  -1
//         1. -1
//           1  -1
      

       
// cnt = 2

// knows = 5