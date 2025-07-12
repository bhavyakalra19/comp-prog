class Solution {
public:
    unordered_map<int,vector<int>> mp;
    unordered_map<int, bool> min_map;
    unordered_map<int, bool> max_map;
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
        min_map[curr] = true;
        if(mp.find(curr) == mp.end()){
            vector<int> nums;
            dfs(curr, 1, n, nums, firstPlayer, secondPlayer); 
            mp[curr] = nums;
        }
        int ans = 1e9;
        for(auto a : mp[curr]){
            if(min_map.find(a) == min_map.end()){
                ans = min(ans, 1 + getMin(n, firstPlayer, secondPlayer, a));
            }
        }
        return ans;
    }

    int getMax(int &n, int &firstPlayer, int &secondPlayer, int &curr){
        if(checkStatus(n, firstPlayer, secondPlayer, curr)){
            return 1;
        }       
        max_map[curr] = true;
        if(mp.find(curr) == mp.end()){
            vector<int> nums;
            dfs(curr, 1, n, nums, firstPlayer, secondPlayer); 
            mp[curr] = nums;
        }
        int ans = -1e9;
        for(auto a : mp[curr]){
            if(max_map.find(a) == max_map.end()){
                ans = max(ans, 1 + getMax(n, firstPlayer, secondPlayer, a));
            }
        }
        return ans;
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
