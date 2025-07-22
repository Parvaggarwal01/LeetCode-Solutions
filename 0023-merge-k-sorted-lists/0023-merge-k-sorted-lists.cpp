class Solution {
public:
    // Function to get the last node of a linked list
    ListNode* last(ListNode* dummy){
        while(dummy->next != NULL){
            dummy = dummy->next;
        }
        return dummy;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }


        ListNode* head = new ListNode(0);  
        ListNode* tail = head;

        for(int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            while(curr != NULL) {
                tail->next = curr;
                tail = tail->next;
                curr = curr->next;
            }
        }


        vector<int> arr;
        ListNode* temp = head->next;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());


        temp = head->next;
        for(int j = 0; j < arr.size(); j++){
            temp->val = arr[j];
            temp = temp->next;
        }

        return head->next;
    }
};
