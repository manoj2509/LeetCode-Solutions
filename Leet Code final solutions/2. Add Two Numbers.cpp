//
// Created by Mj on 11/14/2016.
//

#include <iostream>
#include <stdlib.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Iterate through the linked lists
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0;
        int temp;
        ListNode *ans = new ListNode(0);
        ListNode *ansHead = ans;
        while (l1 && l2) {
            // Add those numbers, store last digit, take carry ahead.
            temp = l1->val + l2->val + carry;
            carry = temp/10;
            temp = temp % 10;
            ans->val = temp;
            if (l1->next && l2->next) {
                ListNode* tempNode = new ListNode(0);
                ans->next = tempNode;
                ans = ans->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1) {
            ListNode* tempNode1 = new ListNode(0);
            ans->next = tempNode1;
            ans = ans->next;
            // Numbers in l1 still left.
            while (l1) {
                temp = l1->val + carry;
                carry = temp/10;
                temp = temp % 10;
                ans->val = temp;
                if (l1->next) {
                    ListNode* tempNode = new ListNode(0);
                    ans->next = tempNode;
                    ans = ans->next;
                }
                l1 = l1->next;
            }
        }
        if (l2) {
            ListNode* tempNode1 = new ListNode(0);
            ans->next = tempNode1;
            ans = ans->next;
            // Numbers in l2 still left.
            while (l2) {
                temp = l2->val + carry;
                carry = temp/10;
                temp = temp % 10;
                ans->val = temp;
                if (l2->next) {
                    ListNode* tempNode = new ListNode(0);
                    ans->next = tempNode;
                    ans = ans->next;
                }
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            ListNode* tempNode1 = new ListNode(0);
            ans->next = tempNode1;
            ans = ans->next;
            ans->val = carry;
        }
        return ansHead;
        // keep adding until one number finishes.
        // Then copy the other one with the carry overs.
        // Return the lists.

    }
};
int main() {

}