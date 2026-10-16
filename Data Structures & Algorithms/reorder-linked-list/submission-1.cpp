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
    ListNode* revL(ListNode* node){
        ListNode* prev = NULL;
        ListNode* cur = node;
        while(cur)
        {
            ListNode* nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* cur_ = head;
        ListNode* fast = cur_;
        ListNode* slow = cur_;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* rev = revL(slow->next);
        slow->next = nullptr;  // split: first half must not still point into the second
        ListNode* cur = head;
        while (rev) {
            ListNode* nextCur = cur->next;
            ListNode* nextRev = rev->next;
            cur->next = rev;
            rev->next = nextCur;
            cur = nextCur;
            rev = nextRev;
        }
    }
};
