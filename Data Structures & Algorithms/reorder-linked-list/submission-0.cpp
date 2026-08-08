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
    ListNode* reverse(ListNode* l)
    {
        ListNode* prev = nullptr;
        ListNode* curr = l;

        while(curr != nullptr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;
        
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        ListNode* first = head;
        ListNode* sec = reverse(slow);

        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;
        while(first!=nullptr && sec != nullptr)
        {
            res->next = first;
            res = res->next;
            first = first->next;

            res->next = sec;
            sec = sec->next;
            res = res->next;
        }

        head = res->next;
    }
};
