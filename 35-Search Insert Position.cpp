class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        int upperIndex = nums.size()-1 , lowerIndex = 0;
        while(upperIndex >= lowerIndex)
        {
            index = (upperIndex + lowerIndex) / 2;
            if(nums[index] == target)
                return index;
            else if(nums[index] <= target)
                lowerIndex = index + 1;
            else
                upperIndex = index - 1;   
        }
        return lowerIndex;
    }
};