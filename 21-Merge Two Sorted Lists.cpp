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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = nullptr;
        ListNode* valToReturn;
        ListNode* newNode;
        ListNode* head1 = list1 , *head2 = list2;
        while(head1 != nullptr || head2 != nullptr)
        {
            if(head1 == nullptr)
            {
                newNode = head2;
                head2 = head2->next;
            }
            else if(head2 == nullptr)
            {
                newNode = head1;
                head1 = head1->next;
            }
            else if(head1->val < head2->val)
            {
                newNode = head1;
                head1 = head1->next;
            }
            else
            {
                newNode = head2;
                head2 = head2->next;
            }
            if(newList == nullptr)
            {
                newList = newNode;
                valToReturn = newNode;
            }
            else
            {
                newList->next = newNode;
                newList = newList->next;
            }
        }
        return valToReturn;
    }
};