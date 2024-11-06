class Solution {
public:
    int getSet(int num){
        int ans = 0;
        while(num > 0){
            ans += (num & 1);
            num = num >> 1;
        }
        return ans;
    }

    void merge(vector<int> &arr, int s, int mid, int e){
        int i = s;
        int j = mid+1;
        vector<int> check;
        while(i <= mid && j <= e){
            if(arr[i] < arr[j]){
                check.push_back(arr[i]);
                i++;
            }else{
                check.push_back(arr[j]);
                j++;
            }
        }
        while(i <= mid){
            check.push_back(arr[i]);
            i++;
        }

        while(j <= e){
            check.push_back(arr[j]);
            j++;
        }

        for(int i = s; i <= e; i++){
            arr[i] = check[i-s];
        }
    }


    void mergeSort(vector<int> &arr, int s, int e){
        if(s < e){
            int mid = (s + e)/2;
            mergeSort(arr,s,mid);
            mergeSort(arr,mid+1,e);
            merge(arr,s,mid,e);
        }
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> check;
        for(int i = 0; i < n; i++){
            check.push_back(getSet(nums[i]));
        }
        int i = 0;
        while(i < n){
            int s = i;
            while(i < n && check[i] == check[s]){
                i++;
            }
            mergeSort(nums,s,i-1);
        }
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                return false;
            }
        }
        return true;
    }
};