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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 1;
        ListNode* temp = head;
        ListNode* previous = nullptr;

        // while(temp->next != nullptr)
        // {
        //     size++;
        //     temp = temp -> next;
        // }

        // int position = size-n+1;
        // // int position = n;
        // ListNode* previous = nullptr;
        // temp = head;
        // int index = 1;
        // while(temp->next != nullptr && index < position)
        // {
        //     previous = temp;
        //     temp = temp->next;
        //     index++;
        // }

        while(temp != nullptr)
        {
            if(previous != nullptr)
            {
                previous = previous->next;
            }
            if(size-n-1 == 0)
            {
                previous = head;
            }
            if(temp->next != nullptr)
            {
                temp = temp->next;
                size++;
            }
            else
                temp = nullptr;
        }
        if(previous == nullptr)
        {
                head = head->next;
        }
        else
        {
            if(previous->next == nullptr)
                return nullptr;
            ListNode* current = previous->next;
            if(current->next == nullptr)
                previous->next = nullptr;
            else
                previous->next = current->next;
            
        }
        return head;
    }
};