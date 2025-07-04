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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        vector<ListNode*> ans(k, nullptr);
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        
        int extraNodes = cnt%k;
        int noOfNodes = cnt/k;
        ListNode* curr = head;
        for(int i = 0; i<k && curr!=NULL; i++){
            int extra=(i<extraNodes)?1:0;
            ans[i] = curr;
            for(int j = 1; j<noOfNodes+extra; j++){
                curr=curr->next;
            }
            ListNode* nextNode = curr->next;
            curr->next = NULL;
            curr=nextNode;
        }
        return ans;
    }
};