class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> check;
        int n = profits.size();
        for(int i = 0; i < n; i++){
            check.push_back({capital[i],profits[i]});
        }
        sort(check.begin(),check.end());
        priority_queue<int> pq;
        int idx = 0;
        while(k > 0){
            while(idx < n && w >= check[idx].first){           
                pq.push(check[idx].second);
                idx++;
            }
            if(pq.empty()){
                break;
            }
            k--;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};