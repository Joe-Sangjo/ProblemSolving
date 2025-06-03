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
    bool isPalindrome(ListNode* head) {
        
        ListNode* cur = head;
        auto max_cnt = 0;
        while(cur != nullptr){
            max_cnt++;
            cur = cur->next;
        }
        if(max_cnt == 1) return true;

        stack<int> st;
        cur = head;
        auto cnt = 0;
        while(cur != nullptr) {
            st.push(cur->val);
            cur = cur->next;
            if(st.size() >= max_cnt/2) break;
        }

        // odd
        if(max_cnt % 2 == 1) {
            cur = cur->next;
        }

        while(cur != nullptr) {
            if(cur->val != st.top()) return false;
            st.pop();
            cur = cur->next;
        }
        return true;
    }
};