class Solution {
public:
    vector<vector<int>> returnVal;
    vector<int> numbers;
    vector<vector<int>> subsets(vector<int>& nums) {
        numbers = nums;
        vector<int> temp;
        returnSubsets(temp , 0);
        return returnVal;
    }

    void returnSubsets(vector<int>& input, int index)
    {
        returnVal.push_back(input);
        for(int i = index; i < numbers.size(); i++ )
        {
            input.push_back(numbers[i]);
            returnSubsets(input, i+1);
            input.pop_back();
        }
    }
};