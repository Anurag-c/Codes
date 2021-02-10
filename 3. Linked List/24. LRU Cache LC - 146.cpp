class LRUCache 
{
    class Node
    {
        public:
        int key;
        int value;
        Node* next = NULL;
        Node* prev = NULL;
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
        }
    };

    void addFirst(Node* temp)
    {
        if(head == NULL)
        {
            this->head = temp;
            this->tail = temp;
        }
        else
        {
            temp->next = this->head;
            this->head->prev = temp;
            this->head = temp;
        }
        this->size++;
    }

    void removeFirst()
    {
        Node* temp = head->next;
        if(temp != NULL) temp->prev = NULL;
        head->next = NULL;
        head = temp;
        this->size--;
    }

    Node* removeTail() // return required to be used in put
    {
        Node* ans = tail;
        Node* temp = tail->prev;
        if(temp != NULL) temp->next = NULL;
        tail->prev = NULL;
        tail = temp;
        this->size--;
        return ans;
    }

    void remove(Node* temp)
    {
        if(temp == NULL) return;

        if(temp == head) removeFirst();
        else if(temp == tail) removeTail();
        else
        {   
            Node* forw = temp->next;
            Node* back = temp->prev;

            back->next = forw;
            forw->prev = back; 

            temp->next = NULL;
            temp->prev = NULL;
            this->size--;
        }
    }

    void moveToHead(Node* temp)
    {
        remove(temp);
        addFirst(temp);
    }

    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
    int capacity;
    unordered_map<int, Node*>hm;

    public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }
    
    int get(int key) 
    {
        if(hm.find(key) == hm.end()) return -1;
        Node* temp = hm[key];
        moveToHead(temp);
        return temp->value;
    }
    
    void put(int key, int value)
    {
        if(hm.find(key) == hm.end())
        {
            Node* temp = new Node(key, value);
            hm[key] = temp;
            addFirst(temp);
            if(this->size > this->capacity)
            {
                temp = removeTail();
                hm.erase(temp->key);
            }
        }
        else
        {
            Node* temp = hm[key];
            temp->value = value;
            moveToHead(temp);
        }
    }
};