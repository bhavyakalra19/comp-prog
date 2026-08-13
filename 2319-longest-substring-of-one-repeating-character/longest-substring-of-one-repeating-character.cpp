class Solution {
public:
    vector<int> best;
    vector<int> prefix;
    vector<int> suffix;
    void createTree(string &s, int curr, int st, int en){
        if(st == en){
            best[curr] = 1;
            prefix[curr] = 1;
            suffix[curr] = 1;
            return;
        }
        int mid = (st + en)/2;
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;
        createTree(s, left, st, mid);
        createTree(s, right, mid + 1, en);

        if(s[mid] == s[mid+1]){
            int len = suffix[left] + prefix[right];
            best[curr] = max(max(best[left], best[right]), len);
            if(prefix[left] == mid - st + 1){
                prefix[curr] = prefix[left] + prefix[right];
            }else{
                prefix[curr] = prefix[left];
            }

            if(suffix[right] == en - mid){
                suffix[curr] = suffix[left] + suffix[right];
            }else{
                suffix[curr] = suffix[right];
            }
        }else{
            prefix[curr] = prefix[left];
            suffix[curr] = suffix[right];
            best[curr] = max(best[left], best[right]);
        }
    }

    void updateTree(string &s, int curr, int st, int en, int idx){
        if(st == en){
            best[curr] = 1;
            prefix[curr] = 1;
            suffix[curr] = 1;
            return;
        }
        int mid = (st + en)/2;
        int left = curr * 2 + 1;
        int right = curr * 2 + 2;
        if(idx <= mid) updateTree(s, left, st, mid, idx);
        if(idx > mid) updateTree(s, right, mid + 1, en, idx);

        if(s[mid] == s[mid+1]){
            int len = suffix[left] + prefix[right];
            best[curr] = max(max(best[left], best[right]), len);
            if(prefix[left] == mid - st + 1){
                prefix[curr] = prefix[left] + prefix[right];
            }else{
                prefix[curr] = prefix[left];
            }

            if(suffix[right] == en - mid){
                suffix[curr] = suffix[left] + suffix[right];
            }else{
                suffix[curr] = suffix[right];
            }
        }else{
            prefix[curr] = prefix[left];
            suffix[curr] = suffix[right];
            best[curr] = max(best[left], best[right]);
        }
    }


    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        best.resize(4 * n, 0);
        prefix.resize(4 * n, 0);
        suffix.resize(4 * n, 0);
        
        createTree(s, 0, 0, n-1);
        vector<int> ans;

        int m = queryIndices.size();
        for(int i = 0; i < m; i++){
            s[queryIndices[i]] = queryCharacters[i];
            updateTree(s, 0, 0, n-1, queryIndices[i]);
            ans.push_back(best[0]);
        }
        return ans;
    }
};
// b b 
// bb a

// if left.suffix.char == right.prefix.char
    // best = max(mx, left.suffix + right.prefix)
    // if suffix.len == left.legth and left.suffix.char == right.prefix.char
    // prefix == suffix + prefix

// prefix suffix best
