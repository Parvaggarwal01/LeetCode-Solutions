class Solution {
public:
    int gcd(int a, int b){
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            int a = temp->val;
            int b = temp->next->val;
            int ans = gcd(a, b);

            ListNode* newNode = new ListNode(ans);
            newNode->next = temp->next;
            temp->next = newNode;

            temp = temp->next->next;
        }

        return head;
    }
};
