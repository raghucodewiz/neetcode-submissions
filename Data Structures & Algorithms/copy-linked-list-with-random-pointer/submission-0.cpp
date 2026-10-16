/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> oldToCopy;

        Node* cur = head;
        while(cur)
        {
            Node* copy = new Node(cur->val);
            oldToCopy[cur] = copy;
            cur = cur->next;
        }

        Node* cur2 = head;
        while(cur2)
        {
            Node* copy2 = oldToCopy[cur2];
            copy2->next = oldToCopy[cur2->next];
            copy2->random = oldToCopy[cur2->random];
            cur2 = cur2->next;
        }

        return oldToCopy[head];
    }
};
