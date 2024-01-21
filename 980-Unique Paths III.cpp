class Solution {
public:

    int count = 0;
    int walkable = 0;
    vector<vector<int>> grids;
    string endingpos;
    int height;
    int width;
    set<string> unwalkable;
    int uniquePathsIII(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();
        string startingpos = "";
        grids = grid;
        //figure out what is the end position, also find out how many walkable paths are present
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(grid[i][j] == 1)
                {
                    startingpos = to_string(i)+to_string(j);
                    walkable++;
                }
                else if (grid[i][j] == 2)
                {
                    endingpos = to_string(i)+to_string(j);
                    walkable++;
                }
                else if (grid[i][j] == 0)
                    walkable++;
                else
                    unwalkable.insert(to_string(i)+to_string(j));
            }
        }
        unordered_set<string> newset = {startingpos};
        calculatePath(startingpos , newset);
        return count;
    }
    void calculatePath(string currPos , unordered_set<string> allPos )
    {
        int currHeight = currPos.at(0) - '0';
        int currWidth = currPos.at(1 )- '0';
        if(currPos == endingpos && allPos.size() == walkable)
        {
            count++;
        }
        else
        {
            //check all 4 directions
            //left
            string leftpos = to_string(currHeight) + to_string(currWidth - 1);
            string rightpos = to_string(currHeight) + to_string(currWidth + 1);
            string toppos = to_string(currHeight - 1) + to_string(currWidth);
            string bottompos = to_string(currHeight + 1) + to_string(currWidth);
            if(currWidth >=1 && !allPos.count(leftpos) && !unwalkable.count(leftpos))
            {
                allPos.insert(leftpos);
                calculatePath(leftpos, allPos);
                allPos.erase(leftpos);
            }
            if(currWidth < width - 1 && !allPos.count(rightpos) && !unwalkable.count(rightpos))
            {
                allPos.insert(rightpos);
                calculatePath(rightpos , allPos);
                allPos.erase(rightpos);
            }
            if(currHeight >=1 && !allPos.count(toppos) && !unwalkable.count(toppos))
            {
                allPos.insert(toppos);
                calculatePath(toppos, allPos);
                allPos.erase(toppos);
            }
            if(currHeight < height - 1 && !allPos.count(bottompos) && !unwalkable.count(bottompos))
            {
                allPos.insert(bottompos);
                calculatePath(bottompos, allPos);
                allPos.erase(bottompos);
            }
            
            
        }
    }
};