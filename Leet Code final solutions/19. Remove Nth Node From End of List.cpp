//
// Created by Mj on 1/25/2017.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) {
        return head;
    }
    ListNode* ptr = head;
    for (int i = 0; i < n; i++) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        return head->next;
    }
    ListNode* removePtr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
        removePtr = removePtr->next;
    }
    // Remove from the pointer.
    ListNode* temp = removePtr->next;
    removePtr->next = temp->next;
    return head;
}


int main() {
    ListNode* head = new ListNode(1);
    ListNode* temp = new ListNode(2);
    // Creating a new node.
    ListNode* ptr = head;
    ptr->next = temp;
    ListNode* ans = removeNthFromEnd(head, 2);
}