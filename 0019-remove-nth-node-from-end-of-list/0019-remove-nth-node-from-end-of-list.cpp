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

        int cnt=0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        int number = cnt-n;
        int curr = 0;
        temp = head;
        if(number == 0){
            return head->next;
        }
        while(temp){
            curr++;
            if(curr == number){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        return head;;
    }
};