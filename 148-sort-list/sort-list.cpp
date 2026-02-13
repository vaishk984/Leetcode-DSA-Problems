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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge2Lists(ListNode* leftHead, ListNode* rightHead){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(leftHead != NULL && rightHead != NULL){
            if(leftHead->val < rightHead->val){
                temp->next = leftHead;
                temp = leftHead;
                leftHead = leftHead->next;
            }else{
                temp->next = rightHead;
                temp = rightHead;
                rightHead = rightHead->next;
            }
        }

        if(rightHead) temp->next = rightHead;
        else temp->next = leftHead;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* middle = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        middle->next = nullptr;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return merge2Lists(leftHead, rightHead);
    }
};