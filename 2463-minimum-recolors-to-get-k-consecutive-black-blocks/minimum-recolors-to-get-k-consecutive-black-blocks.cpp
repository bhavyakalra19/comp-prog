class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0;
        int j = 0;
        int ans;
        int sum = 0;
        int n = blocks.size();
        while(i < k) if(blocks[i++] == 'W') sum++;
        ans = sum;
        for(; i < n; i++){
            if(blocks[j++] == 'W') sum--;
            if(blocks[i] == 'W') sum++;
            ans = min(ans, sum);
        }
        return ans;
    }
};