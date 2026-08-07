#define ll long long
class Solution {
public:
   ll gcd(ll a ,ll b){
    if(a>b) swap(a,b);
    if(a==0) return b;
    return gcd(b%a,a);
   }
    string fillRemNum(int slots,ll t){
        string ans="";
        for(int d=9;d>=2;d--){
            while(t%d==0){
                ans.push_back(d+'0');
                t/=d;
            }
        }
        while(ans.size()<slots){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string smallestNumber(string num, long long t) {
        int n=num.size();
        vector<int>prime={2,3,5,7};
        ll val=t;
        for(auto it:prime){
            while(val%it==0){
                val/=it;
            }
        }
        if(val!=1) return "-1";

        vector<ll>res(n+1,t);
        for(int i=0;i<n;i++){
            int digit=num[i]-'0';
            if(digit==0) break;
            res[i+1]=res[i]/(gcd(1LL*digit,res[i]));
        }
        if(res.back()==1) return num;
        int st=n-1;
        int zeroIdx=num.find('0');
        if(zeroIdx!=string::npos){
            st=zeroIdx;
        }
        for(int i=st;i>=0;i--){
            ll remVal=res[i];
            int digit=num[i]-'0';
            int freeSlots=n-i-1;
            for(int d=digit+1;d<=9;d++){
                ll remFutherVal=remVal/(gcd(remVal,d));
                string remFurtherNum=fillRemNum(freeSlots,remFutherVal);
                if(remFurtherNum.size()==freeSlots) return num.substr(0,i)+string(1,d+'0')+remFurtherNum;
            }
        }
        return fillRemNum(n+1,t);
    }
};