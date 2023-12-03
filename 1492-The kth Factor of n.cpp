class Solution {
public:
    int kthFactor(int n, int k) {
        int totalfactors = 1;
        int currentFactor = 1;
        vector<int> factors;
        factors.push_back(1);
        if(k==1)
            return 1;
        for(int i = 2; i <= n/i ; i++)
        {
            if(n%i==0)
            {
                currentFactor++;
                if(currentFactor == k)
                    return i;
                factors.push_back(i);
            }
        }
        int sub = (n/factors[currentFactor - 1]==factors[currentFactor - 1])? 1 : 0;//1 = odd
        if(k <= (currentFactor * 2 - sub))
            return (n/factors[(2 * currentFactor - k -sub)]);
        return -1;
    }
};