//
// Created by Mj on 1/3/2017.
//
# include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }
    // copy head location to a pointer.
    ListNode* ptr1 = l1;
    ListNode* ptr2 = l2;

    // traverse to a new location.
    ListNode* ansHead = new ListNode(-1);
    ListNode* ptr3 = ansHead;
    if (ptr1->val < ptr2->val) {
        ListNode* temp = new ListNode(ptr1->val);
        ptr3->next = temp;
        ptr3 = ptr3->next;
        ptr1 = ptr1->next;
    } else {
        ListNode* temp = new ListNode(ptr2->val);
        ptr3->next = temp;
        ptr3 = ptr3->next;
        ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL ) {
        if (ptr1->val < ptr2->val) {
            ListNode* temp = new ListNode(ptr1->val);
            ptr3->next = temp;
            ptr3 = ptr3->next;
            ptr1 = ptr1->next;
        } else {
            ListNode* temp = new ListNode(ptr2->val);
            ptr3->next = temp;
            ptr3 = ptr3->next;
            ptr2 = ptr2->next;
        }
    }
    if (ptr1 == NULL) {
        // Copy rest of ptr2.
        while (ptr2 != NULL) {
            ListNode* temp = new ListNode(ptr2->val);
            ptr3->next = temp;
            ptr3 = ptr3->next;
            ptr2 = ptr2->next;
        }
    } else {
        // copy rest of ptr1.
        while (ptr1 != NULL) {
            ListNode* temp = new ListNode(ptr1->val);
            ptr3->next = temp;
            ptr3 = ptr3->next;
            ptr1 = ptr1->next;
        }
    }
    return ansHead->next;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // iterate over the vectors and combine two into one. One from last and one from first into first.
    // In the end return the first ListNode.
    int i = 0;
    int j = lists.size() - 1;
    if (lists.size() == 0) {
        return NULL;
    }
    while (j > i) {
        for (int it = i; it < j/2   ; it++) {
            lists[it] = mergeTwoLists(lists[it], lists[j - it]);
        }
        j = j / 2;
    }
    return lists[0];
}

int main() {
    std::vector <ListNode*> lists;
    ListNode* ans = mergeKLists(lists);
}