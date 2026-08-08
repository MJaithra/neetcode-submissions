/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* r = res;

        int carry = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            int v = l1->val + l2->val + carry;
            r->next = new ListNode(v % 10);
            carry = v/10;

            r = r->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr)
        {
            int v = l1->val + carry;
            r->next = new ListNode(v % 10);
            carry = v/10;

            r = r->next;
            l1 = l1->next;
        }

        while(l2 != nullptr)
        {
            int v = l2->val + carry;
            r->next = new ListNode(v % 10);
            carry = v/10;

            r = r->next;
            l2 = l2->next;
        }

        while( carry > 0)
        {
            r->next = new ListNode(carry % 10);
            carry = carry / 10;
            r = r->next;
        }

        return res->next;
    }
};
