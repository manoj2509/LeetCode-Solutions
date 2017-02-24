//
// Created by Mj on 2/21/2017.
//
#include <iostream>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) {
        return head;
    }
    // Step 1: Insert a node in between the nodes.
    RandomListNode *ptr = head;
    while (ptr) {
        RandomListNode *temp = new RandomListNode(ptr->label);
        temp->next = ptr->next;
        ptr->next = temp;
        ptr = ptr->next->next;

    }
    // Step 2: Copy the random pointer from original nodes.
    RandomListNode *newHead = head->next;
    ptr = head;
    while (ptr) {
        if (ptr->random) {
            ptr->next->random = ptr->random->next;
        } else {
            ptr->next->random = NULL;
        }

        ptr = ptr->next->next;

    }
    // Step 3: Now segregate the two lists from each other.
    ptr = head;
    RandomListNode *newptr = newHead;
    while (ptr) {
        ptr->next = newptr->next;
        if (newptr->next) {
            newptr->next = ptr->next->next;
        } else {
            newptr->next = NULL;
        }

        ptr = ptr->next;
        newptr = newptr->next;
    }
    return newHead;
}
int main() {
    // Testing our function.

}