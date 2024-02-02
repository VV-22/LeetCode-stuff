class Solution {
public:
    int maxCoins(vector<int>& piles) {
        ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);//seems to improve performance?
        sort(piles.begin() , piles.end() , greater<int>());
        int vv = 0 , bob = 0;
        for(int i = 1; i< piles.size() - bob;i+=2)
        {
            vv += piles[i];
            bob++;
        }
        return vv;
    }
};