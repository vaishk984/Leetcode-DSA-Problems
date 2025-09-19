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
        ListNode* temp = head;
        int len = 1;

        if(head == nullptr){
            return nullptr;
        }

        while(temp->next != nullptr){
            temp = temp->next;
            len++;
        }

        int position = k % len;

        if(position == 0) return head;

        ListNode* curr = head;

        for(int i = 0; i<len - position - 1; i++){
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;
        temp->next = head;

        return newHead;
    }
};