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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        int del = cnt/2;
        int curr = 0;
        temp = head;
        if(cnt == 1){
            return NULL;
        }
        while(temp){
            curr++;
            if(curr == del){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        return head;
        
    }
};