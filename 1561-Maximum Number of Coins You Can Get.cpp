class Solution {
public:
    int maxCoins(vector<int>& piles) {
        priority_queue<int> sortedPiles;
        for(int i : piles)
            sortedPiles.push(i);
        int bob = 0;
        int alice = 0;
        int vv = 0;
        while(sortedPiles.size() > bob)
        {
            sortedPiles.pop();
            alice++;
            vv += sortedPiles.top();
            sortedPiles.pop();
            bob++;
        }
        return vv;
    }
};