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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        int index = cnt-n;
        if(index == 0){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        temp = head;
        int curr = 0;
        while(temp!=NULL){
            if(curr == index-1){
                ListNode* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                break;
            }
            temp=temp->next;
            curr++;   
        }
        return head;
    }
};