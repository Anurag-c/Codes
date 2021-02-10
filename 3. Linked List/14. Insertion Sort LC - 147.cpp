void insert(ListNode* dummy, ListNode* temp)
{
    ListNode* prev = NULL;
    while(dummy != NULL)
    {
        if(dummy->val > temp->val) break;
        prev = dummy;
        dummy = dummy->next;
    }
    prev->next = temp;
    temp->next = dummy;
}

ListNode* insertionSortList(ListNode* head) 
{
    ListNode *dummy = new ListNode(INT_MIN);
    
    while(head != NULL)
    {
        ListNode* forw = head->next;
        insert(dummy,head);
        head = forw;
    }
    return dummy->next;
}