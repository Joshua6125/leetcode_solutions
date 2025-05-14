struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head) return head;
    if (!head->next) return head;

    struct ListNode* cur = head;
    struct ListNode* next = head->next;

    while (next) {
        if (next->val != cur->val) {
            cur = next;
        } else {
            cur->next = next->next;
        }
        if (next->next) {
            next = next->next;
        } else {
            break;
        }
    }
    return head;
}
