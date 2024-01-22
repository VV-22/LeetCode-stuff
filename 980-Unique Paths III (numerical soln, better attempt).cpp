class Solution {
public:
    int startingPosX, startingPosY , finalPosX, finalPosY, maxX, maxY;
    int walkable = 0;
    int solutions = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        maxX = grid.size();
        maxY = grid[0].size();
        for(int i = 0; i < maxX ; i++)
        {
            for(int j = 0; j < maxY ; j++)
            {
                if(grid[i][j] != -1)
                    walkable++;
                if(grid[i][j] == 1)
                {
                    startingPosX = i;
                    startingPosY = j;
                }
                else if(grid[i][j] == 2)
                {
                    finalPosX = i;
                    finalPosY = j;
                }
            }
        }
        calculatePaths(startingPosX , startingPosY , grid , 1);
        return solutions;
    }

    void calculatePaths(int currPosX , int currPosY , vector<vector<int>>& grid , int walkedCount)
    {
        if(currPosX < 0 || currPosY < 0 || currPosX >= maxX || currPosY >= maxY || grid[currPosX][currPosY] == -1)
            return;
        if(grid[currPosX][currPosY] == 2 && walkedCount == walkable)
            solutions++;
        int prevVal = grid[currPosX][currPosY];
        grid[currPosX][currPosY] = -1;
        calculatePaths(currPosX - 1 , currPosY , grid, walkedCount + 1 );
        calculatePaths(currPosX , currPosY - 1 , grid, walkedCount + 1 );
        calculatePaths(currPosX + 1 , currPosY , grid, walkedCount + 1 );
        calculatePaths(currPosX , currPosY + 1 , grid, walkedCount + 1 );
        grid[currPosX][currPosY] = prevVal;
    }
};