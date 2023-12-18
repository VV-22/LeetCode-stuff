class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        set<int> passedValues;
        bool gameOver = false;
        int currentHolder = 1;
        int index = 1;
        passedValues.insert(currentHolder);
        while(!gameOver)
        {
            currentHolder = ((currentHolder + (index * k))% n); 
            currentHolder = currentHolder == 0 ? n : currentHolder; 
            if(passedValues.find(currentHolder) != passedValues.end())
            {
                gameOver = true;
            }
            passedValues.insert(currentHolder);
            index++;
        }
        //now form return values
        vector<int> returningValue;
        for(int i = 1; i<=n ; i++)
        {
            if(passedValues.find(i) == passedValues.end())
                returningValue.push_back(i);
        }
        return returningValue;
    }
};