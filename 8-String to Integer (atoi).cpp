class Solution {
public:
    int myAtoi(string s) {
        s.erase(0 , s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        if(s.empty())
            return 0;
        int sign = s[0] == '-'?-1:1;
        if(s[0]=='+' || s[0] == '-')
            s = s.substr(1);
        long num = 0;
        for(char c : s)
        {
            if(!isdigit(c))
                break;
            num = num * 10 + (c - '0');
            if(num * sign > INT_MAX )
                return INT_MAX;
            else if(num * sign < INT_MIN)
                return INT_MIN;
        }
        return (int)(num * sign);
        
    }
};