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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL){
            return head;
        }

        int cnt = 0;
        ListNode* temp = head;

        while(cnt<2){
            if(temp==NULL){
                return head;
            }
            temp = temp->next;
            cnt++;
        }

        ListNode* prevNode = swapPairs(temp);

        cnt = 0;
        temp = head;

        while(cnt<2){
            ListNode* next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            cnt++;
        }

        return prevNode;
    }
};