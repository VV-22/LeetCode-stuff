class Solution {
public:
    char repeatedCharacter(string s) {
       int min = s.size();
       char currentChar = s.at(0);
       for(int i = 0 ; i < s.size() -1; i ++)
       {
           for ( int j = i+1; j< s.size(); j++)
           {
               if(s.at(i) == s.at(j) && j < min)
               {
                   min = j;
                   currentChar = s.at(i);
               }
           }
       }
       return currentChar;
    }
};