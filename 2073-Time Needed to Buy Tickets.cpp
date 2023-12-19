class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int timeReq = 0;
        int numTickets = tickets[k];
        for(int i = 0; i <= k; i++)
            timeReq += (tickets[i] < numTickets ? tickets[i] : numTickets);
        for(int i = k + 1; i < tickets.size(); i++)
            timeReq += (tickets[i] < (numTickets - 1) ? tickets[i] : (numTickets - 1));
        return timeReq;
    }
};