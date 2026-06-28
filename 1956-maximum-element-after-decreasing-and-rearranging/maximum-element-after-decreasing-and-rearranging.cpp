// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         sort(arr.begin(), arr.end());
//         int n = arr.size();
//         arr[0] = 1;
//         for(int i = 1; i < n; i++){
//             if(arr[i] - arr[i-1] > 1){
//                 arr[i] = arr[i-1] + 1;
//             }
//         }
//         return arr[n-1];
//     }
// }; 
//above method is of sorting o(n * logn) time and O(1) space
//decrease 

// rearrange

//below method by hashmap -> o(n) time and O(n) space

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
       
        int n = arr.size();
        vector<int> mp(n+1, 0);
        for(int i = 0; i < n; i++){
            mp[min(arr[i], n)]++;
        }

        int i = 0;
        int curr = 1;
        int used_smaller = 0;
        // why i used this used_smaller value as if i dont get any count i want its just bigger value not maz value, just bigger value to be decrease so that bigger value remain untouched coz we can decrease value not increase so keeping increased value makes our answer better
        while(i < n){
            int used = min(mp[curr], used_smaller);
            mp[curr] -= used;
            used_smaller -= used;
            if(mp[curr] > 0){
                i += mp[curr];
            }else{
                i++;
                used_smaller++;
            }
            curr++;
        }
        return curr - 1;
    }
};

