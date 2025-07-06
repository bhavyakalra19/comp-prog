class Solution {
public:
    int getCommon(string w1, string w2){
        int curr = 0;
        for(int j = 0; j < min(w1.size(), w2.size()); j++){
            if(w1[j] != w2[j]) break;
            curr++;
        }
        return curr;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if(n <= 2){
            vector<int> ans(n, 0);
            return ans;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> check;
        vector<int> ans;
        for(int i = 0; i < n-1; i++){
            int curr = getCommon(words[i], words[i+1]);
            if(i < 3){
                pq.push(curr);
            }else if(curr > pq.top()){
                pq.pop();
                pq.push(curr);
            }
            check.push_back(curr);
        }
        vector<int> max_arr(3, 0);
        for(int i = 0; i < 3; i++){
            if(!pq.empty()){
                max_arr[i] = pq.top();
                pq.pop();
            }
        }
        sort(max_arr.begin(), max_arr.end(), greater<int>());
        int mx3 = max_arr[2];
        int mx2 = max_arr[1];
        int mx1 = max_arr[0];
        for(int i = 0; i < n; i++){
            int curr = (i == n-1 ? INT_MIN : check[i]);
            int prev = (i == 0 ? INT_MIN : check[i-1]);
            int thirdMx = 0;
            if(i != 0 && i != n-1){
                thirdMx = getCommon(words[i-1], words[i+1]);
            }
            if(curr < prev) swap(curr, prev);
            if(curr == mx1){
                if(prev == mx2){
                    ans.push_back(max(mx3, thirdMx));
                }else{
                    ans.push_back(max(mx2, thirdMx));
                }
            }else{
                ans.push_back(max(mx1, thirdMx));
            }
        }
        return ans;
    }
};
