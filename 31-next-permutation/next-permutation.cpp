class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        stack<int> st;
        st.push(n-1);
        while(i >= 0){
            if(nums[i] < nums[i+1]){
                int check;
                while(!st.empty() && nums[i] < nums[st.top()]){
                    check = st.top();
                    st.pop();
                }
                swap(nums[i], nums[check]);
                break;
            }else{
                st.push(i);
            }
            i--;
        }
        auto it = nums.begin();
        it += i + 1;
        sort(it, nums.end());
    }
};
