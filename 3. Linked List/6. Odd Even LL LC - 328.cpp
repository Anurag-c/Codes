ListNode* oddEvenList(ListNode* head) 
{
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* oddHead = head;
    ListNode* evenHead = head->next;
    ListNode* oddTail = oddHead;
    ListNode* evenTail = evenHead;
    
    ListNode* curr = evenHead->next;
    bool isOdd = true;
    while(curr != NULL)
    {
        if(isOdd)
        {
            oddTail->next = curr;
            oddTail = curr;
            isOdd = false;
        }
        else
        {
            evenTail->next = curr;
            evenTail =curr;
            isOdd = true;
        }
        curr = curr->next;
    }
    oddTail->next = evenHead;
    evenTail->next = NULL;
    return oddHead;
}