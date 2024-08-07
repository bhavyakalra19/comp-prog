class Solution {
public:
    string getNum(int num){
        if(num == 0){
            return "";
        }
        string ans = "";
        int n = num%10;
        num /= 10;
        switch(n){
            case 0:
                break;
            case 1:
                ans += "One";
                break;
            case 2:
                ans += "Two";
                break;
            case 3:
                ans += "Three";
                break;
            case 4:
                ans += "Four";
                break;
            case 5:
                ans += "Five";
                break;
            case 6:
                ans += "Six";
                break;
            case 7:
                ans += "Seven";
                break;
            case 8:
                ans += "Eight";
                break;
            case 9:
                ans += "Nine";
                break;
        }
        if(num == 0){
            return ans;
        }
        int s = n;
        n = num % 10;
        num /= 10;
        switch(n){
            case 0:
                break;
            case 1:
                switch(s){
                    case 0:
                        ans = "Ten";
                        break;
                    case 1:
                        ans = "Eleven";
                        break;
                    case 2:
                        ans = "Twelve";
                        break;
                    case 3:
                        ans = "Thirteen";
                        break;
                    case 4:
                        ans = "Fourteen";
                        break;
                    case 5:
                        ans = "Fifteen";
                        break;
                    case 6:
                        ans = "Sixteen";
                        break;
                    case 7:
                        ans = "Seventeen";
                        break;
                    case 8:
                        ans = "Eighteen";
                        break;
                    case 9:
                        ans = "Nineteen";
                        break;
                }
                break;
            case 2:
                ans = ans != "" ? "Twenty " + ans : "Twenty";
                break;
            case 3:
                ans = ans != "" ? "Thirty " + ans : "Thirty";
                break;
            case 4:
                ans = ans != "" ? "Forty " + ans : "Forty";
                break;
            case 5:
                ans = ans != "" ? "Fifty " + ans : "Fifty";
                break;
            case 6:
                ans = ans != "" ? "Sixty " + ans : "Sixty";
                break;
            case 7:
                ans = ans != "" ? "Seventy " + ans : "Seventy";
                break;
            case 8:
                ans = ans != "" ? "Eighty " + ans : "Eighty";
                break;
            case 9:
                ans = ans != "" ? "Ninety " + ans : "Ninety";
                break;
        }
        if(num == 0){
            return ans;
        }
        if(ans != ""){
            ans = " " + ans;
        }
        n = num%10;
        switch(n){
            case 0:
                break;
            case 1:
                ans = "One Hundred" + ans;
                break;
            case 2:
                ans = "Two Hundred" + ans;
                break;
            case 3:
                ans = "Three Hundred" + ans;
                break;
            case 4:
                ans = "Four Hundred" + ans;
                break;
            case 5:
                ans = "Five Hundred" + ans;
                break;
            case 6:
                ans = "Six Hundred" + ans;
                break;
            case 7:
                ans = "Seven Hundred" + ans;
                break;
            case 8:
                ans = "Eight Hundred" + ans;
                break;
            case 9:
                ans = "Nine Hundred" + ans;
                break;
        }
        return ans;
    }

    string numberToWords(int num) {
        if(num == 0){
            return "Zero";
        }
        string ans = "";
        string check;
        vector<string> arr{"","Thousand","Million","Billion"};
        ans = getNum(num%1000);
        num /= 1000;
        if(num == 0){
            return ans;
        }
        for(int i = 1; i < 4; i++){
            check = getNum(num%1000);
            if(check != ""){
                if(ans == ""){
                    ans = check + " " + arr[i];
                }else{
                    ans = check + " " + arr[i] + " " + ans;
                } 
            }  
            num /= 1000;
            if(num == 0){
                return ans;
            }        
        }
        return ans;
    }
};