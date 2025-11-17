class MyLinkedList {
    ListNode* head;
    int size;
public:
    MyLinkedList() {
        head = new ListNode(0);
        size = 0;   
    }
    
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        ListNode* curr = head->next;
        for(int i=0; i<index; i++)
            curr = curr->next;

        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0) index = 0;
        if(index > size) return;

        ListNode* curr = head;
        for(int i=0; i<index; i++)
            curr = curr->next;
        
        ListNode* newNode = new ListNode(val);
        newNode->next = curr->next;
        curr->next = newNode;
        size ++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        ListNode* curr = head;
        for(int i=0; i<index; i++)
            curr = curr->next;

        curr->next = curr->next->next;        
        size--;
    }
};