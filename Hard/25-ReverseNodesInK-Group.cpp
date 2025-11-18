class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;

        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count < k){
            temp = temp->next;
            count ++;
        }

        if(count < k) return head;

        ListNode* nextNode = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        count = 0;
        
        while(curr != NULL && count < k){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count ++;
        }
        if(nextNode != NULL) 
            head->next = reverseKGroup(nextNode, k);

        return prev;
    }
};