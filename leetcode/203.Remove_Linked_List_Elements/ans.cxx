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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return head;
        }

        ListNode* first = new ListNode(-1, head);

        auto here = first;
        while(here->next) {
            auto next = here->next;
            if(next->val == val) {
                auto temp = next;
                here->next = next->next;
                delete temp;
            } else {
                here = here->next;
            }

        }
        return first->next;
    }
};