class MyLinkedList 
{
public:
    class linkObject
    {
        public:
        int value;
        linkObject* next;

        linkObject()
        {
            this->next = nullptr;
        }

        linkObject(int val)
        {
            this->value = val;
            this->next = nullptr;
        }

        linkObject(int val , linkObject* nextNode)
        {
            value = val;
            next = nextNode;
        }
    };
    linkObject* head;
    int count;
    MyLinkedList() 
    {
        count = 0;
        head = nullptr;
    }
    
    int get(int index) 
    {
        if(index >= count)
            return -1;
        else
        {
            int tempCount = 0;
            linkObject* temp = head;
            while(temp->next != nullptr && tempCount < index)
            {
                temp = temp->next;
                tempCount++;
            }
            return temp->value;
        }
    }
    
    void addAtHead(int val) 
    {
        linkObject* newHead = new linkObject(val, head);
        head = newHead;
        count++;
    }
    
    void addAtTail(int val) 
    {
        if(head==nullptr)
        {
            head = new linkObject(val);
            count++;
        }
        else
        {
            linkObject* temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new linkObject(val, nullptr);
            count++;
        }
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index > count)
            return;
        else if(index == 0)
            addAtHead(val);
        else if(index == count)
            addAtTail(val);
        else
        {
            linkObject* temp = head;
            int currInd = 0;
            while(currInd < (index - 1) )
            {
                temp = temp->next;
                currInd++;
            }
            linkObject* inserter = new linkObject(val , temp->next);
            temp->next = inserter;
            count++;
        }
    }
    
    void deleteAtIndex(int index) 
    {
        if(head == nullptr)
            return;
        if(index == 0 && head->next!= nullptr)
        {
            head = head->next;
            count--;
        }
        else if(index >= count)
            return;
        else
        {
            linkObject* temp = head;
            int indCount = 0;
            while(indCount < (index - 1))
            {
                temp = temp->next;
                indCount++;
            }
            temp->next = (temp->next) != nullptr? (temp->next)->next : nullptr;
            count--;
        }
    }

    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */