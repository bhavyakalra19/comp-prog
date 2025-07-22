class Solution {
public:
    void createPalindrome(string s, int &k, bool &od, int &len, vector<string> &ans){
        if(s.size() >= len){
            string a = s;
            reverse(a.begin(), a.end());
            if(od){
                ans.push_back(s + a.substr(1));
            }else{
                ans.push_back(s + a);
            }
            return;
        }
        for(int i = 0; i < k; i++){
            createPalindrome(s + (char)(i + '0'), k, od, len, ans);
        }
    }

    void getAns(int len, int k, vector<string> &check){
        bool od = false;
        if(len % 2 != 0){
            od = true;
        }
        len = (len + 1)/2;
        for(int i = 1; i < k; i++){
            string a = to_string(i);
            createPalindrome(a, k, od, len, check);
        }
    }

    long long checkAns(string &s, int &k){
        long long num = 0;
        long long a = 1;
        for(int i = 0; i < s.size(); i++){
            int b = s[i] - '0';
            num += a * b;
            a *= k;
        }
        vector<int> arr;
        long long num1 = num;
        while(num > 0){
            arr.push_back(num % 10);
            num /= 10;
        }
        int i = 0;
        int j = arr.size() - 1;
        while(i < j){
            if(arr[i] != arr[j]) return -1;
            i++;
            j--;
        }
        return num1;
    }

    long long kMirror(int k, int n) {
        int ans = 0;
        long long sum = 0;
        for(int i = 1; i < 200; i++){
            vector<string> arr;
            getAns(i, k, arr);
            //check if palindrome is palindrome in base_10
            for(auto a : arr){
                long long b = checkAns(a, k);
                if(b != -1){
                    ans++;
                    sum = sum + b;
                    if(ans == n) return sum;
                }
            }
        }
        return sum;
    }
};


//create palidrome of smallest size (i+1 / 2)
// check their base 10 if it's palindrome
// return ans