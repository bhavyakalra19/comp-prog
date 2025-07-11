class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> check;
        int prev = 0;
        for(int i = 0; i < n; i++){
            int curr = startTime[i] - prev;
            if(i > 2){
                if(curr > pq.top()){
                    pq.pop();
                    pq.push(curr);
                }
            }else{
                pq.push(curr);
            }
            check.push_back(curr);
            prev = endTime[i];
        }
        if(pq.size() == 2){
            pq.push(eventTime - endTime[n-1]);
        }else if(eventTime - endTime[n-1] > pq.top()){
            pq.pop();
            pq.push(eventTime - endTime[n-1]);
        }
        check.push_back(eventTime - endTime[n-1]);

        vector<int> max_arr;
        while(!pq.empty()){
            cout << pq.top() << endl;
            max_arr.push_back(pq.top());
            pq.pop();
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int mx1 = check[i];
            int mx2 = check[i+1];
            if(mx1 < mx2){
                swap(mx1, mx2);
            }
            int dist = endTime[i] - startTime[i];
            if(mx1 == max_arr[2]){
                if(mx2 == max_arr[1]){
                    if(dist > max_arr[0]){
                        ans = max(ans, mx1 + mx2);
                    }else{
                        ans = max(ans, mx1 + mx2 + dist);
                    }
                }else{
                    if(dist > max_arr[1]){
                        ans = max(ans, mx1 + mx2);
                    }else{
                        ans = max(ans, mx1 + mx2 + dist);
                    }
                }
            }else{
                if(dist > max_arr[2]){
                    ans = max(ans, mx1 + mx2);
                }else{
                    ans = max(ans, mx1 + mx2 + dist);
                }
            }
        }
        return ans;
    }
};