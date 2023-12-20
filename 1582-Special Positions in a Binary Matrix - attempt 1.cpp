class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        bool flag = false;
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j< mat[i].size(); j++)
            {
                flag = false;
                if(mat[i][j] == 1)
                    flag = true;
                if(flag)
                {
                    for(int k = 0; k < i ; k++)
                    {
                        if(mat[k][j] == 1)
                        {
                            flag = false;
                            break;
                        }
                    }
                    for(int k = i + 1; k < mat.size(); k++)
                    {
                        if(mat[k][j] == 1)
                        {
                            flag = false;
                            break;
                        }
                    }
                    for(int k = 0; k < j; k++)
                    {
                        if(mat[i][k] == 1)
                        {
                            flag = false;
                            break;
                        }
                    }
                    for(int k = j + 1; k < mat[i].size(); k++)
                    {
                        if(mat[i][k] == 1)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag)
                    count++;
            }
        }
        return count;
    }
};