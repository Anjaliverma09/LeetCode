class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // Method 1: Length Difference Approach
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

class Solution_HashSet {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // Method 2: Using HashSet
        unordered_set<ListNode*> seen;

        while (headA != NULL) {
            seen.insert(headA);
            headA = headA->next;
        }
        while (headB != NULL) {
            if (seen.count(headB))
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};
