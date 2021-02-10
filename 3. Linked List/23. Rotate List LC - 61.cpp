ListNode* rotateRight(ListNode* head, int k) 
{
    if(head == NULL || k == 0) return head;
    
    ListNode* temp = head;
    int len = 1;
    while(temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    k = k % len;
    //if(k == 0) return head; => just a small optimization
    temp->next = head; // form ring
    
    temp = head;
    int travel = len - k;
    for(int i = 1; i < travel ; i++)
        temp = temp->next;
    
    head = temp->next;
    temp->next = NULL; // break ring here
    return head;
}