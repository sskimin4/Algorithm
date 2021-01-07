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

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;
        map<Node *, Node *> address;
        Node *root = new Node(head->val);
        address[head] = root;
        root->random = head->random;
        Node *answer = root;
        head = head->next;
        while (head != NULL)
        {
            root->next = new Node(head->val);
            root->next->random = head->random;
            root = root->next;
            address[head] = root;
            head = head->next;
        }
        root = answer;
        while (root != NULL)
        {
            if (address.count(root->random))
                root->random = address[root->random];
            root = root->next;
        }

        return answer;
    }
};