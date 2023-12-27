class Solution {
public:
    string reverseParentheses(string s) {
        string newString = "";   
        stack<int> st;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')')
            {
                reverse(s.begin() + st.top() + 1 , s.begin() + i);
                st.pop();
            }
        }
        for(int i = 0; i<s.size();i++)
            if(s[i] != '(' && s[i] != ')')
                newString += s[i];
        return newString;
    }
};