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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr && head->next == nullptr) {
            return head;
        }
        ListNode* here = head;

        while(here->next != nullptr) {
            // std::cout <<head->val << " " << head->next->val << std::endl;
            if(here->val == here->next->val) {
                ListNode* temp = here->next;
                here->next = here->next->next;
                delete temp;
            } else {

                here = here->next;
            }
            
        }

        return head;
    }
};