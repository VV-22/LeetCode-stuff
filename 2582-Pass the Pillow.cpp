class Solution 
{
    public:
        int passThePillow(int n, int time) 
        {
            ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);//seems to improve performance?
            int run = time/(n-1);
            if(n > time)
                return time+1;
            if(run % 2 == 0)
                return time - run*(n-1) + 1;
            else
                return n - (time - run*(n-1));
        }
};