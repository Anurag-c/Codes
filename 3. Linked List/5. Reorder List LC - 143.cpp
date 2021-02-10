// middle can be changed no difference will be caused
ListNode *middle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverse(ListNode *head)
{
    if(head == NULL || head->next == NULL) return head;
    ListNode *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}
void reorderList(ListNode* head) 
{
    if(head == NULL||head->next == NULL) return;
    
    ListNode* p1 = head;
    ListNode* mid = middle(head);
    ListNode* p2 = reverse(mid->next);
    mid->next = NULL;
    
    ListNode* forward = NULL;
    
    while(p2 != NULL)
    {
        forward = p1->next;
        p1->next = p2;
        p1 = forward;
        
        forward = p2->next;
        p2->next = p1;
        p2 = forward;
    }
}

// convert reorderd back to original  
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
    evenTail->next = NULL;
    oddTail->next = reverse(evenHead);
    return oddHead;
}