class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0){
            pq.push({a,'a'});
        }
        if(b > 0){
            pq.push({b, 'b'});
        }
        if(c > 0){
            pq.push({c, 'c'});
        }
        string ans = "";
        int n = -1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(n > -1 && ans[n] == it.second){
                if(pq.empty()){
                    return ans;
                }
                auto sec = pq.top();
                pq.pop();
                pq.push(it);
                if(sec.first < it.first){
                    ans += sec.second;
                    n++;
                    if(sec.first > 1){
                        pq.push({sec.first - 1, sec.second});
                    }
                    continue;
                }
                for(int i = 0; i < min(2,sec.first); i++){
                    n++;
                    ans += sec.second;
                }
                if(sec.first > 2){
                    pq.push({sec.first - 2, sec.second});
                }
            }else{
                for(int i = 0; i < min(2,it.first); i++){
                    n++;
                    ans += it.second;
                }
                if(it.first > 2){
                    pq.push({it.first - 2, it.second});
                }
            }
        }
        return ans;
    }
};