ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    
    while(p1 != p2)
    {
        p1 = (p1 != NULL) ? p1->next : headB;
        p2 = (p2 != NULL) ? p2->next : headA;
    }
    return p1;
}

// method - 2

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode* tail = headA;
    while(tail != NULL) tail = tail->next;
    tail->next = headB;
    
    ListNode* ans = detectCycle(headA);
    tail->next = NULL // revert changes
    return ans;
}

