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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        }

        if(!list2){
            return list1;
        }

        auto first = new ListNode(-101, list1);
        auto here = first;
        auto cmp = list2;
        while(cmp && here->next){ 
            if((cmp->val >= here->val) && (here->next->val >= cmp->val)) {
                std::cout << "Insertion case = here:" <<here->val << " here->next:" << here->next->val << "  // cmp:" << cmp->val<<std::endl; 
                auto temp = cmp->next;
                cmp->next = here->next;
                here->next = cmp;                 
                cmp = temp;
            } 
            here = here->next;
        }
        if(!here->next && cmp){
            here->next = cmp;
        }
        return first->next;
    }
};