class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int slow2 = nums[0];
        while(slow2 != slow){
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};

// 3 -> 4 -> 2 -> 3 -> 4