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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head;
        int count = 0;
        while (ptr)
        {
            ptr = ptr -> next;
            count++;
        }
        if (count % 2 == 0)
        {
            count = count / 2 + 1;
        }
        else
        {
            count /= 2;
            count++;
        }
        ListNode* temp = head;
        while (--count)
        {
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* Brute(ListNode* head)
    {
        return middleNode(head);
    }
};