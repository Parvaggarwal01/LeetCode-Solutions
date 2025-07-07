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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        ListNode* final = new ListNode(0);
        ListNode* tail = final;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            if(cnt%2 != 0){
                tail->next = new ListNode(temp->val);
                tail=tail->next;
            }
            temp=temp->next;
        }
        temp=head;
        cnt = 0;
        while(temp != NULL){
            cnt++;
            if(cnt%2 == 0){
                tail->next = new ListNode(temp->val);
                tail=tail->next;
            }
            temp=temp->next;
        }
        return final->next;
    }
};