class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int l1 = 0 , l2 = (nums[0] < nums[1])? 0 : 1;
        for(int i = 1; i < nums.size();i++)
        {
            if(nums[i]>nums[l1])
            {
                l2 = l1;
                l1 = i;
            }
            else if(nums[i] > nums[l2])
                l2 = i;
        }
        if(nums[l1] >= nums[l2]  * 2)
            return l1;
        else
            return -1;
    }
};