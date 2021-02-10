//Link : https://www.interviewbit.com/problems/reverse-alternate-k-nodes/
ListNode* reverse(ListNode* head) 
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
    return back;
}
    
ListNode* reverseKGroup(ListNode* head, int k, bool flag)
{
    if(head == NULL) return head;
    
    ListNode* revEnd = head;
    
    for(int i = 1; i < k && revEnd != NULL; i++) revEnd = revEnd->next;
    if(revEnd == NULL) return head;
    
    ListNode* knext = revEnd->next;
    if(flag == true)
    {
        revEnd->next = NULL;
        ListNode* newHead = reverse(head);
        head->next = reverseKGroup(knext, k, !flag);
        head = newHead;
    }
    else revEnd->next = reverseKGroup(knext, k, !flag);
    return head;
}