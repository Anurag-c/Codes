
ListNode* merge(ListNode* l1, ListNode* l2) 
{
    ListNode* anshead = new ListNode(-1);
    ListNode* anstail = anshead;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val <= l2->val)
        {
            anstail->next = l1;
            l1 = l1->next;
        }
        else
        {
            anstail->next = l2;
            l2 = l2->next;
        }
        anstail = anstail->next;
    }
    anstail->next = (l1 != NULL) ? l1 : l2 ;
    return anshead->next;
}

ListNode* middle(ListNode* head) 
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* sortList(ListNode* head) 
{
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* mid = middle(head);
    ListNode* secondHalf = mid->next;
    mid->next = NULL;
    
    return merge(sortList(head), sortList(secondHalf));
}