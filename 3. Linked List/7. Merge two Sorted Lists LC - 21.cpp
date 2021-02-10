ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode* anshead = new ListNode(-1);
    ListNode* anstail = anshead;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val <= l2->val)
        {
            anstail->next = l1;
            anstail = anstail->next;
            l1 = l1->next;
        }
        else
        {
            anstail->next = l2;
            anstail = anstail->next;
            l2 = l2->next;
        }
    }
    anstail->next = (l1 != NULL) ? l1 : l2 ;
    return anshead->next;
}