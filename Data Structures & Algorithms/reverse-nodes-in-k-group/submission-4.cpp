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
    ListNode* getKth(ListNode* cur, int k)
    {
        while(cur && k>0)
        {
            cur = cur->next;
            k--;
        }
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while(true)
        {
            ListNode* kth = getKth(prevGroup, k);
            if(!kth) break;

            ListNode* groupHead = prevGroup->next;
            ListNode* groupNext = kth->next;

            kth->next = nullptr;
            prevGroup->next = reverse(groupHead);
            groupHead->next = groupNext;
            prevGroup = groupHead;
        }
        return dummy.next;
    }
    ListNode* reverse(ListNode* cur)
    {
        ListNode* prev = nullptr;
        ListNode* node = cur;
        while(node)
        {
            ListNode* nextNode = node->next;
            node->next = prev;
            prev = node;
            node = nextNode;
        }
        return prev;
    }
};
