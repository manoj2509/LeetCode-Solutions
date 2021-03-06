//
// Created by Mj on 1/26/2017.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL) {
        return false;
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
                return true;
            }
        }
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* temp = new ListNode(2);
    head->next = temp;
    bool ans = hasCycle(head);
}