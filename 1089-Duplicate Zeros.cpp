class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> locations;
        int size = arr.size();
        for(int i = 0; i<arr.size(); i++)
        {
            if(arr[i] == 0)
                locations.push_back(i);
        }
        for(int i = locations.size()-1; i>=0; i--)
        {
            arr.insert(arr.begin() + locations[i] , 0);
        }
        arr.resize(size);
    }
};