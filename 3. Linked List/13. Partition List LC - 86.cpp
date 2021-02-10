ListNode* partition(ListNode* head, int x) 
{
    if(head == NULL || head->next == NULL) return head;
    ListNode* less = new ListNode(-1);
    ListNode* great = new ListNode(-1);
    
    ListNode* p1 = less;
    ListNode* p2 = great;
    while(head != NULL)
    {
        if(head->val < x)
        {
            p1->next = head;
            p1 = head;
        }
        else
        {
            p2->next = head;
            p2 = head;
        }
        head = head->next;
    }
    p2->next = NULL;
    p1->next = great->next;
    return less->next;
}