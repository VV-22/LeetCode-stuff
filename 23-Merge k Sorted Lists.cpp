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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        else if (lists.size() == 1)
            return lists[0];
        else
        {
            ListNode* merged = lists[0];
            for(int i = 1; i< lists.size();i++)
            {
                merged = mergeTwoLists(merged, lists[i]);
            }
            return merged;
        }
        return nullptr;
    }

    void printLS (ListNode* lst)
    {
        while(lst != nullptr)
        {
            cout<<lst->val<< endl;
            lst = lst->next;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* lst1 = list1;
        ListNode* lst2 = list2;
        ListNode* result = new ListNode();
        
        if(lst1 ==  nullptr && lst2 == nullptr)
            return nullptr;
        else if(lst1 == nullptr || lst2 == nullptr)
        {
            if(lst1 != nullptr)
            {
                result = lst1;
                lst1 = lst1->next;
            }
            else
            {
                result = lst2;
                lst2 = lst2->next;
            }
        }
        else
        {
            int val1 = lst1!=nullptr ? lst1->val : INT_MAX;
            int val2 = lst2!=nullptr ? lst2->val : INT_MAX;

            if(val1 < val2)
            {
                result = lst1;
                lst1 = lst1 ->next;
            }
            else
            {
                result = lst2;
                lst2 = lst2 ->next;
            }
        }
        ListNode* valToReturn = result;
        while(lst1 != nullptr || lst2 != nullptr)
        {
            int val1 = lst1!=nullptr ? lst1->val : INT_MAX;
            int val2 = lst2!=nullptr ? lst2->val : INT_MAX;
            if(val1 < val2)
            {
                result -> next = lst1;
                lst1 = lst1->next != NULL ? lst1->next : nullptr;
                result = result -> next;
            }
            else
            {
                result -> next = lst2;
                lst2 =  lst2->next != NULL ? lst2->next : nullptr;
                result = result -> next;
            }
        }
        return valToReturn;
    }
};