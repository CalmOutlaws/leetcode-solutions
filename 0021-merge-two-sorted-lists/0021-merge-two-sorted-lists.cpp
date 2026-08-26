class Solution {
public:
    void InsertAtTail(ListNode*& Head, ListNode*& Tail, int data)
    {
        if (Head == NULL)
        {
            ListNode* newNode = new ListNode(data);
            Head = newNode;
            Tail = newNode;
            return;
        }

        ListNode* newNode = new ListNode(data);

        Tail->next = newNode;

        Tail = newNode;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> listOne;
        ListNode* temp = list1;
        while (temp != NULL) {
            listOne.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* temp2 = list2;
        while (temp2 != NULL)
        {
            listOne.push_back(temp2->val);
            temp2 = temp2->next;
        }

        sort(listOne.begin(), listOne.end());

        ListNode* Head = NULL;
        ListNode* Tail = NULL;

        for (int i = 0; i < listOne.size(); i++)
        {
            InsertAtTail(Head, Tail, listOne[i]);
        }
        return Head;
    }
};