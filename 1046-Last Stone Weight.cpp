class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        int first = stones[0] , second = stones[1], firstIndex = 0, secondIndex = 1 ;
        bool gameOver = false;
        if(stones.size() == 1)
            return stones[0];
        while(!gameOver)
        {
            first = 0;
            second = 0; 
            firstIndex = -1;
            secondIndex = -1 ;
            //find first and second highest.
            for(int i = 0; i<stones.size();i++)
            {
                if(stones[i] > first)
                {
                    first = stones[i];
                    firstIndex = i;
                }
            }
            for(int i = 0; i <stones.size(); i++)
            {
                if(stones[i] > second && stones[i] <= first && i != firstIndex)
                {
                    second = stones[i];
                    secondIndex = i;
                }
            }
            // cout<<"first : "<<firstIndex << " second : "<<secondIndex<<endl;
            if(second == 0)
            {
                gameOver = true;
                break;
            }
            //subtract from array
            int val = first - second;
            stones[firstIndex] = val;
            // cout<<"firstindex : "<<stones[firstIndex]<<endl;
            stones[secondIndex] = 0;
            // cout<<"secondindex : "<<stones[secondIndex]<<endl;
        }
        return first;
    }
};