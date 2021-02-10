
ListNode* reverseList(ListNode* head) 
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

//recursive
ListNode* reverseList(ListNode* head) 
{
    if(head == NULL || head->next == NULL) 
        return head;
    
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}