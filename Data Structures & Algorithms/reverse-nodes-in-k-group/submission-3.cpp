class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) break;

            ListNode* groupHead = groupPrev->next;
            ListNode* groupNext = kth->next;

            kth->next = nullptr;
            groupPrev->next = reverse(groupHead);
            groupHead->next = groupNext;

            groupPrev = groupHead;
        }
        return dummy.next;
    }

private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};