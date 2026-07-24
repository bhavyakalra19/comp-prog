class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        // int cnt = 0;

        //count number of zeroes only
        vector<int> check;
        check.push_back(-1);
        // vector<int> count(n);
        int oc = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                // cnt++;
                check.push_back(i);
            }else{
                oc++;
                // this will take care of continuos 1 only for starting till first zero
                ans += i - check[check.size() - 1]; 
            }
            int zc = 1;
            int x = check.size() - 1;
            while(zc * zc <= oc && x > 0){
                int min_gap = zc * zc;
                int en = check[x-1];
                int curr = check[x];
                int st = min(curr, i - (zc + zc * zc) + 1);
                // cout << i << " -> " << st << " " << en << endl;
                // this will calculate from one zero to another zero but we have to take care of cont
                if(en < st){
                    ans += st - en;
                }
                x--;
                zc++;
            }
            // count[i] = cnt;
        }
        return ans;
    }
};

// j = min(zero_index, i - )


// 1 1 1 1 0 0 1

// 0 1 2 3 4 5 6