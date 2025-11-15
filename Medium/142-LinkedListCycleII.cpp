class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                while(head != slow){
                    head = head->next;
                    slow = slow->next;
                }
            return slow;
            }
        }
        return NULL;
    }
};