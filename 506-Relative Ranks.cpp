class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<int> sortedScore(score.size());
        copy(score.begin(), score.end(), sortedScore.begin());
        sort(sortedScore.begin(), sortedScore.end() , greater<int>());
        vector<string> valtoReturn (score.size());
        for(int i = 0; i < score.size(); i++)
        {
            int location = find(sortedScore.begin(), sortedScore.end(), score[i]) - sortedScore.begin();
            valtoReturn[i] = location == 0? "Gold Medal" : location == 1 ? "Silver Medal" : location == 2 ? "Bronze Medal" : to_string( location + 1);
        }
        return valtoReturn;
    }
};