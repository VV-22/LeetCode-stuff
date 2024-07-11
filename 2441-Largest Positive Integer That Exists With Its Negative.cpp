class Solution {
public:
    int findMaxK(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
        int max = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(max < nums[i] && std::find(std::begin(nums), std::end(nums), (nums[i] * -1)) != std::end(nums))
                max = nums[i];
        }
        return max;
    }
};