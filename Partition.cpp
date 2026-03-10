class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode a(0), b(0), *p=&a, *q=&b;
        while(head){
            (head->val < x ? p : q)->next = head;
            (head->val < x ? p : q) = (head->val < x ? p : q)->next;
            head = head->next;
        }
        q->next = NULL;
        p->next = b.next;
        return a.next;
    }
};
