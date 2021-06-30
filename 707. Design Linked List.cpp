// class ListNode {
// public:
//     int val;
//     ListNode *next;
//     ListNode() {
//         this->val = 0;
//         this->next = nullptr;
//     }
//     ListNode(int val) {
//         this->val = val;
//         this->next = nullptr;
//     }
// }

class MyLinkedList {
public:
    ListNode *head;
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->head = nullptr;
    }
    
    ~MyLinkedList() {
        ListNode *trav = this->head;
        while (trav) {
            ListNode *temp = trav;
            trav = trav->next;
            delete temp;
        }
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *trav = this->head;
        while (index-- && trav) {
            trav = trav->next;
        }
        if (!trav) return -1;
        return trav->val;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (!this->head) {
            this->head = new ListNode(val);
            return;
        }
        
        ListNode *node = new ListNode(val);
        node->next = this->head;
        this->head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *p = this->head;
        if (!p) {
            this->addAtHead(val);
            return;
        }
        while (p->next) {
            p = p->next;
        }
        p->next = new ListNode(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            this->addAtHead(val);
            return;
        }
        ListNode *trav = this->head;
        while (--index && trav) {
            trav = trav->next;
        }
        if (!trav && index == -1) {
            this->addAtTail(val);
            return;
        }
        ListNode *temp = trav->next;
        trav->next = new ListNode(val);
        trav->next->next = temp;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0) {
            ListNode *temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        } 
        ListNode *trav = this->head;
        while (--index && trav) {
            trav = trav->next;
        }
        
        if (!trav && index == -1 || !trav) {
            return;
        }
        ListNode *temp = trav->next;
        // Ternary operator for deleting last node
        trav->next = trav->next ? trav->next->next : nullptr;
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
