class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]] = 1;
        }
        int mx = 0;
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                int cnt = 0;
                int a = arr[i];
                int b = arr[j];
                int c = a + b;
                while(mp.find(c) != mp.end()){
                    a = b;
                    b = c;
                    cnt++;
                    c =  a + b;
                }
                if(cnt > 0) mx = max(mx, cnt + 2);
            }
        }
        return mx;
    }
};