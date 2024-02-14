class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) 
    {
        ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
        int currentMax = nums[0];
        vector<long long> score;
        long long currentSum = nums[0] * 2;
        score.push_back(nums[0] * 2);
        for(int i = 1; i < nums.size(); i++)
        {
            currentMax = max(currentMax, nums[i]);
            currentSum = currentSum + currentMax + nums[i];
            score.push_back(currentSum);
        }
        return score;
    }
};