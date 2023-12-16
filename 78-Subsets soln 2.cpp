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
        if(index==numbers.size())
        {
            returnVal.push_back(input);
        }
            
        if(index < numbers.size())
        {
            input.push_back(numbers[index]);
            returnSubsets(input , index + 1);
            input.pop_back();
            returnSubsets(input, index + 1);
        }
    }
};