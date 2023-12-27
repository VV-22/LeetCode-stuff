class Solution {
public:
    string reverseParentheses(string s) {
        bool opensPresent = false;
        int startingIndex = s.find_first_of('(');
        int endingIndex = s.find_last_of(')');
        string newString = s;
        bool flag = false;
        if(startingIndex == 0)
        {
            newString = reverseFunc(newString.substr(startingIndex + 1 , s.size() - 2));
            startingIndex = newString.find_first_of(')');
            endingIndex = newString.find_last_of('(');
            flag = !flag;
        }
        // cout<<"removed outermost: "<<newString<<endl;
        while(startingIndex != string::npos)
        {
            // cout<<"entering while loop"<<endl;
            newString = newString.substr(0 , startingIndex) + reverseFunc(newString.substr(startingIndex + 1 , endingIndex - startingIndex -1)) + newString.substr(endingIndex + 1);
            if(flag)
            {
                startingIndex = newString.find_first_of('(');
                endingIndex = newString.find_last_of(')');
            }
            else
            {
                startingIndex = newString.find_first_of(')');
                endingIndex = newString.find_last_of('(');
            }
            flag = !flag;
        }
        return newString;
    }

    string reverseFunc(string s)
    {
        // cout<<"entry to reversefunc: "<<s<<endl;
        string returnVal = "";
        for(auto i = s.rbegin(); i!=s.rend();i++)
            returnVal.push_back(*i);
        // cout<<"exit of reversefunc: "<<returnVal<<endl;
        return returnVal;
    }
};