//
// Created by Mj on 1/26/2017.
//

//
// Created by Mj on 1/26/2017.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode* ptr1 = head;
    ListNode* ptr2 = head;
    ListNode* entry = head;
    while (ptr2 != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;        // Incremented at twice the speed.
        if (ptr2) {
            ptr2 = ptr2->next;
        }
        if (ptr2) {
            if (ptr2 == ptr1) {
                while(entry != ptr1) {          // TODO very important trick question of linked list.
                    ptr1 = ptr1->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
    }
    return NULL;

}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* temp = new ListNode(2);
    head->next = temp;
    ListNode* ans = detectCycle(head);
}