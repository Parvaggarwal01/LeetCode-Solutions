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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        
        ListNode* temp = head;
        int cnt = 1;
        while(temp->next != NULL){
            cnt++;
            temp=temp->next;
        }
        temp->next = head;
        k = k % cnt;
        int stepsToNewTail = cnt - k;
        temp = head;
        for (int i = 0; i < stepsToNewTail - 1; i++) {
            temp = temp->next;
        }

        ListNode* newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};