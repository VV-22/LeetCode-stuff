/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        //redoing this with a priority queue
        if(lists.size() == 0)
            return nullptr;
        else if(lists.size() == 1)
            return lists[0];
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0; i< lists.size(); i++)
        {
            ListNode* temp = lists[i];
            while(temp != nullptr)
            {
                pq.push(temp -> val);
                temp = temp -> next != nullptr ? temp -> next : nullptr;
            }
        }
        if(pq.size() == 0)
            return nullptr;
        ListNode* newList = new ListNode(pq.top());
        ListNode* start = newList;
        pq.pop();
        while(pq.size() > 0)
        {
            start -> next = new ListNode(pq.top());
            pq.pop();
            start = start -> next;
        }
        return newList;
    }
};