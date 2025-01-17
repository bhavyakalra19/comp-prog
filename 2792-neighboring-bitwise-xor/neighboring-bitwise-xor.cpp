class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n == 1){
            return derived[0] == 0;
        }
        int first = 0;
        int curr = derived[0] == 1 ? 1 : 0;
        for(int i = 1; i < n - 1; i++){
            if(derived[i] == 0){
                if(curr == 0){
                    curr = 0;
                }else{
                    curr = 1;
                }
            }else{
                if(curr == 0){
                    curr = 1;
                }else{
                    curr = 0;
                }
            }
        }
        cout << curr << endl;
        if(curr ^ first == derived[n-1]){
            return true;
        }
        first = 1;
        curr = derived[0] == 1 ? 0 : 1;
        for(int i = 1; i < n-1; i++){
            if(derived[i] == 0){
                if(curr == 0){
                    curr = 0;
                }else{
                    curr = 1;
                }
            }else{
                if(curr == 0){
                    curr = 1;
                }else{
                    curr = 0;
                }
            }
        }
        if(curr ^ first == derived[n-1]){
            return true;
        }
        return false;
    }
};
