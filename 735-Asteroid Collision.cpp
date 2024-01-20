class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> returningVal;
        stack<int> asteroidStack;
        asteroidStack.push(asteroids[0]);
        for(int i = 1; i < asteroids.size(); i++)
        {
            int compareVal = asteroidStack.size()> 0 ? asteroidStack.top() : INT_MIN;int currAst = asteroids[i];
            if(compareVal > 0 && currAst < 0)
            {
                bool colliding = true;
                while(colliding)
                {
                    if(asteroidStack.size() == 0)
                    {
                        asteroidStack.push(currAst);
                        colliding = false;
                        continue;
                    }
                    int currentVal = asteroidStack.top();
                    if( currentVal > 0 )
                    {
                        if(abs(currentVal) < abs(currAst))
                        {
                            asteroidStack.pop();
                        }
                        else if(abs(currentVal) > abs(currAst))
                        {
                            colliding = false;
                        }
                        else
                        {
                            asteroidStack.pop();
                            colliding = false;
                        }
                    }
                    else
                    {
                        colliding = false;
                        asteroidStack.push(currAst);
                    }
                }
            }
            else
            {
                asteroidStack.push(currAst);
            }
        }
        //now put the stack into an array
        while(asteroidStack.size() > 0)
        {
            returningVal.push_back(asteroidStack.top());
            asteroidStack.pop();
        }
        std::reverse(returningVal.begin() , returningVal.begin() + returningVal.size());
        return returningVal;
    }
};