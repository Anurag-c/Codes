void reverse(ListNode* head) 
{
    ListNode* back = NULL;
    ListNode* curr = head;
    ListNode* forward = NULL;
    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = back;
        back = curr;
        curr= forward;
    }
}

ListNode* reverseKGroup(ListNode* head, int k) \
{
    if(head == NULL || head->next == NULL || k == 1) return head; // if(head == NULL) also works
    
    ListNode* revEnd = head;
    
    for(int i = 1; i < k && revEnd != NULL; i++) revEnd = revEnd->next;
    if(revEnd == NULL) return head;
    
    ListNode* knext = revEnd->next;
    revEnd->next = NULL;
    reverse(head); // for our comfort we can also take ListNode* newHead = reverse(head);
    head->next = reverseKGroup(knext, k);  
    // remember that after reversing our head will revEnd and revEnd will be head
    //i.e; head and tail get swapped
    return revEnd;
}