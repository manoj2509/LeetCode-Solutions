//
// Created by Mj on 1/3/2017.
//
# include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        std::cout << "Reached 1";
        return head;
    }
    ListNode* ptr1 = head;
    ListNode* ptr2 = head->next;
    ListNode* prev;
    ListNode* newHead = ptr2;
    while (ptr1 && ptr2) {
        std::cout << ptr1->val << "--" << ptr2->val << std::endl;
        if (prev) {
            prev->next = ptr2;
        }
        ptr1->next = ptr2->next;
        ptr2->next = ptr1;
        prev = ptr1;
        ptr1 = ptr1->next;
        if (ptr1->next) {
            ptr2 = ptr1->next;
        }
    }
    return newHead;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* temp = new ListNode(2);
    ListNode* ptr = head;
    ptr->next = temp;
    ListNode* ans = swapPairs(head);
}