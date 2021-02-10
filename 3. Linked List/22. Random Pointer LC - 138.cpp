Node* copyRandomList(Node* head) 
{
    if(head == NULL) return head; 
    //head->next == NULL return head should not be done 
    //because it will be shallow copy not deep copy
    
    //Step - 1
    Node* curr = head;
    while(curr != NULL)
    {
        Node* forw = curr->next;
        Node* dup = new Node(curr->val);
        dup->next = forw;
        curr->next = dup;
        curr = forw;
    }
    
    //Step - 2
    curr = head;
    while(curr != NULL) // curr->next != NULL is not necessary because curr->next always exist
    {
        Node* dup = curr->next;
        Node* forw = curr->next->next;
        Node* org_rndm = curr->random;
        
        dup->random = (org_rndm != NULL) ? org_rndm->next : NULL; // if someone's random is NULL
        curr = forw;
    }
    
    //Step - 3
    Node* dupHead = head->next;
    Node* org = head;
    Node* dup = dupHead;
    while(org != NULL) // org->next != NULL is not necessary because org->next always exist
    {
        Node* Oforw = org->next->next;
        Node* Dforw = (dup->next != NULL) ? dup->next->next : NULL; // 1->1->N case
        
        org->next = Oforw;
        dup->next = Dforw;
        
        org = Oforw;
        dup = Dforw;
    }
    return dupHead;
}