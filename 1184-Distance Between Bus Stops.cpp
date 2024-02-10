class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int startCount = 0, middleCount = 0, lastCount = 0;
        if(start > destination)
        {
            start = start + destination;
            destination = start - destination;
            start = start - destination;
        }
        for(int i = 0; i <start; i++)
            startCount += distance[i];
        for(int i = start; i < destination; i++)
            middleCount += distance[i];
        for(int i = destination; i < distance.size(); i++)
            lastCount += distance[i];
        if(startCount + lastCount < middleCount)
            return startCount + lastCount;
        else
            return middleCount;
    }
};