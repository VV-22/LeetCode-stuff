class Solution {
public:
    int longestPalindrome(string s) {
        int upperCase[26] = {0};
        int lowerCase[26] = {0};

        for(int i = 0; i<s.size(); i++)
        {
            if(isupper(s[i]))
                upperCase[(int(s[i]) - 'A')] ++;
            else
                lowerCase[(int(s[i]) - 'a')] ++;
        }
        int evenCount = 0;
        int odd =  0;
        for(int i = 0; i < 26; i++)
        {
            if(upperCase[i]!= 0 && upperCase[i] % 2 == 0)
            {
                evenCount+= upperCase[i];
            }
            else if(upperCase[i]!= 0)
            {
                evenCount+= (upperCase[i] - 1);
                odd = 1;
            }
            if(lowerCase[i]!= 0 && lowerCase[i] % 2 == 0)
            {
                evenCount+= lowerCase[i];
            }
            else if(lowerCase[i]!= 0)
            {
                evenCount+= (lowerCase[i] - 1);
                odd = 1;
            }
        }
    
        return (evenCount + odd);
    }
};