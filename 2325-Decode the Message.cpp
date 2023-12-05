class Solution {
public:
    string decodeMessage(string key, string message) {
        int index = 1;
        int subTable[26] = {0};
        int subtractNo = (int)'a';
        for(int i = 0 ; i<key.size();i++)
        {
            if(key.at(i) == ' ')
                continue;
            if(subTable[((int)key.at(i) - 97)] < 1)
            {
                subTable[((int)key.at(i) - 97)] = index;
                index++;
            }
        }
        string finalmessage = "";
        for(int i = 0; i < message.size(); i++)
        {
            if(message.at(i) == ' ')
            {
                finalmessage.append(" ");
                continue;
            }
            finalmessage.push_back(char(subTable[message.at(i) - subtractNo] + subtractNo - 1));
        }
        return finalmessage;
    }
};