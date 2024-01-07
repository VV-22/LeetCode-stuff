class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int onesCount = 0, zerosCount = 0;
        for(int i = 0; i< s.length(); i++)
        {
            if(s[i] == '1')
                onesCount++;
            else
                zerosCount++;
        }
        cout<<"ones count :"<<onesCount<<"\nZeros count: "<<zerosCount<<endl;
        string ones = "";
        ones.insert(ones.length() , onesCount -1 , '1');
        cout<<ones<<endl;
        string zeros = "";
        zeros.insert(zeros.length(),zerosCount , '0');
        return (ones + zeros + "1");
    }
};