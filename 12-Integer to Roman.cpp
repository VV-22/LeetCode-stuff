class Solution {
public:
    string intToRoman(int num) {
        int outerNum = num % 10;
        int tensNum = (num/10) > 0 ? (num%100)/10 : 0;
        int hundredthsNum = (num/100) > 0 ? (num%1000)/100 : 0;
        int thousandthsNum = (num / 1000) > 0 ? (num % 10000)/1000 : 0;
        string roman = "";
        if(thousandthsNum == 3)
            roman = roman + "MMM";
        else if(thousandthsNum == 2)
            roman = roman + "MM";
        else if(thousandthsNum == 1)
            roman = roman + "M";
        if(hundredthsNum == 9)
            roman = roman + "CM";
        else if(hundredthsNum == 8)
            roman = roman + "DCCC";
        else if(hundredthsNum == 7)
            roman = roman + "DCC";
        else if(hundredthsNum == 6)
            roman = roman + "DC";
        else if(hundredthsNum == 5)
            roman = roman + "D";
        else if(hundredthsNum == 4)
            roman = roman + "CD";
        else if(hundredthsNum == 3)
            roman = roman + "CCC";
        else if(hundredthsNum == 2)
            roman = roman + "CC";
        else if(hundredthsNum == 1)
            roman = roman + "C";
        if(tensNum == 9)
            roman = roman + "XC";
        else if(tensNum == 8)
            roman = roman + "LXXX";
        else if(tensNum == 7)
            roman = roman + "LXX";
        else if(tensNum == 6)
            roman = roman + "LX";
        else if(tensNum == 5)
            roman = roman + "L";
        else if(tensNum == 4)
            roman = roman + "XL";
        else if(tensNum == 3)
            roman = roman + "XXX";
        else if(tensNum == 2)
            roman = roman + "XX";
        else if(tensNum == 1)
            roman = roman + "X";
        if(outerNum == 9)
            roman = roman + "IX";
        else if(outerNum == 8)
            roman = roman + "VIII";
        else if(outerNum == 7)
            roman = roman + "VII";
        else if(outerNum == 6)
            roman = roman + "VI";
        else if(outerNum == 5)
            roman = roman + "V";
        else if(outerNum == 4)
            roman = roman + "IV";
        else if(outerNum == 3)
            roman = roman + "III";
        else if(outerNum == 2)
            roman = roman + "II";
        else if(outerNum == 1)
            roman = roman + "I";
        return roman;
    }
};