class Solution {
public:
    int n;
    bool getAns(string s, int c, int numOps){
        int i = 0;
        int ans = 0;
        if(c == 1){
            int need0 = 0;
            for(int i=0;i<n;i++){
                if(i%2==0) {if(s[i]=='1') need0++;}
                else {if(s[i]=='0') need0++;}
            }
            int need1 = 0;
            for(int i=0;i<n;i++){
                if(i%2==1) {if(s[i]=='1') need1++;}
                else {if(s[i]=='0') need1++;}
            }
            ans = min(need1, need0);
            return ans <= numOps;
        }
        while(i < n){
            char a = s[i];
            int cnt = 0;
            while(a == s[i]){
                i++;
                cnt++;
            }
            ans += (cnt/(c+1));
        }
        return ans <= numOps;
    }

    int minLength(string s, int numOps) {
        n = s.size();
        int st = 1;
        int en = n;
        while(st < en){
            int mid = (st + en)/2;
            if(getAns(s,mid,numOps)){
                en = mid;
            }else{
                st = mid + 1;
            }
        }
        return en;
    }
};
