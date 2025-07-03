/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       unordered_map<ListNode*, int> mp;
       while(headB!=NULL){
        mp[headB]++;
        headB=headB->next;
       } 
       while(headA){
        if(mp.count(headA)){
            break;
        }
        headA=headA->next;
       }
       return headA;
    }
};