class Solution {
public:
    int sumBase(int n, int k) {
        //convert base first
        int rem = n;
        list<int> num;
        int temp = 0;
        while(rem >=k)
        {
            temp = rem / k;
            num.push_front(rem - temp * k);
            rem = temp;
        }
        num.push_front(rem);
        //sum
        return std::accumulate(num.begin(), num.end(), 0);
    }
};