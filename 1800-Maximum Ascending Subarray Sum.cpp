class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;
        int currentSum = 0;
        int currentMax = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > currentMax)
                currentSum += nums[i];
            else
                currentSum = nums[i];
            maxSum = maxSum < currentSum ? currentSum : maxSum;
            currentMax = nums[i];
        }
        return maxSum;
    }
};