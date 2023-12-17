class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        string numString1, numString2;
        for(int i = 0; i < nums1.size(); i++)
            numString1 += ( " , " + to_string(nums1[i]) );
        for(int i = 0; i < nums2.size(); i++)
            numString2 += (" , " + to_string(nums2[i]) );
        numString1 += " , ";
        numString2 += " , ";
        int val1 = 0, val2 = 0;
        for(int i = 0 ; i < nums1.size(); i++)
        {
            if(numString2.find(", " + to_string(nums1[i]) + " ,") != string::npos)
                val1++;
        }
        for(int i = 0 ; i < nums2.size(); i++)
        {
            if(numString1.find(", " + to_string(nums2[i]) + " ,") != string::npos)
                val2++;
        }
        vector<int> returnval = {val1, val2};
        return returnval;
    }
};