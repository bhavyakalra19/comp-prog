class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_map<int, int> min_map;
    unordered_map<int, int> max_map;
    void dfs(int &curr, int i, int j, vector<int> &nums, int &firstPlayer, int &secondPlayer){
        while(i <= j && (curr & (1 << i))){
            i++;
        }
        while(i <= j && (curr & (1 << j))){
            j--;
        }
        if(i >= j){
            nums.push_back(curr);
            return;
        }
        if(i != firstPlayer && i != secondPlayer){
            curr |= (1 << i);
            dfs(curr, i+1, j-1, nums, firstPlayer, secondPlayer);
            curr ^= (1 << i);
        }
        if(j != secondPlayer && j != firstPlayer){
            curr |= (1 << j);
            dfs(curr, i+1, j-1, nums, firstPlayer, secondPlayer);
            curr ^= (1 << j);
        }
    }
    
    bool checkStatus(int &n, int &firstPlayer, int &secondPlayer, int &curr){
        int i = 1;
        int j = n;
        int fc = 0;
        int sc = 0;
        while(i < firstPlayer){
            if((curr & (1 << i)) == 0){
                fc++;
            }
            i++;
        }
        while(j > secondPlayer){
            if((curr & (1 << j)) == 0){
                sc++;
            }
            j--;
        }
        if(fc == sc){
            return 1;
        }
        return false;
    }

    int getMin(int &n, int &firstPlayer, int &secondPlayer, int &curr){
        if(checkStatus(n, firstPlayer, secondPlayer, curr)){
            return 1;
        }
        if(min_map.find(curr) != min_map.end()){
            return min_map[curr];
        }
        if(mp.find(curr) == mp.end()){
            vector<int> nums;
            dfs(curr, 1, n, nums, firstPlayer, secondPlayer); 
            mp[curr] = nums;
        }
        int ans = 1e9;
        for(auto a : mp[curr]){
            ans = min(ans, 1 + getMin(n, firstPlayer, secondPlayer, a));
        }
        return min_map[curr] = ans;
    }

    int getMax(int &n, int &firstPlayer, int &secondPlayer, int &curr){
        if(checkStatus(n, firstPlayer, secondPlayer, curr)){
            return 1;
        }       
        if(max_map.find(curr) != max_map.end()){
            return max_map[curr];
        }
        if(mp.find(curr) == mp.end()){
            vector<int> nums;
            dfs(curr, 1, n, nums, firstPlayer, secondPlayer); 
            mp[curr] = nums;
        }
        int ans = -1e9;
        for(auto a : mp[curr]){
            ans = max(ans, 1 + getMax(n, firstPlayer, secondPlayer, a));
        }
        return max_map[curr] = ans;
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int a = (1 << (n + 1)) - 1;
        int mx = ceil(log2(n));
        int curr = 0;
        int a1 = getMin(n, firstPlayer, secondPlayer, curr);
        curr = 0;
        int b1 = getMax(n, firstPlayer, secondPlayer, curr);
        return {a1,b1};
    }
};
