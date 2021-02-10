ListNode* swapPairs(ListNode* head) 
{
    // If the list has no node or has only one node left.
    if ((head == nullptr) || (head->next == nullptr)) return head;
        
    // Nodes to be swapped
    ListNode* firstNode = head;
    ListNode* secondNode = head->next;

    // Swapping
    firstNode->next  = swapPairs(secondNode->next);
    secondNode->next = firstNode;

    // Now the head is the second node
    return secondNode;
}