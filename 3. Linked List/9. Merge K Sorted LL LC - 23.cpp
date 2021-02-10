ListNode* merge(ListNode* l1, ListNode* l2) 
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

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if(lists.size() == 0) return NULL;
    int k = lists.size();
    int interval = 1;
    while(interval < k)
    {
        for(int i = 0; i < k - interval ; i = i + (2 * interval))
        {
            lists[i] = merge(lists[i], lists[i + interval]); // i + interval < k => i < k - interval
        }
        interval = interval * 2;
    }
    return lists[0];
}

// recursive
ListNode* mergeK(vector<ListNode*>& lists, int start, int end)
{
    if(start >= end) return lists[start];
    
    int mid = (start + end)/2;
    ListNode* list1 = mergeK(lists, start, mid);
    ListNode* list2 = mergeK(lists, mid + 1, end);
    
    return merge(list1, list2);
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if(lists.size() == 0) return NULL;
    return mergeK(lists, 0, lists.size() - 1);
}