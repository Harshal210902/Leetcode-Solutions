class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*>umap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* delnode)
    {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if(umap.find(key)!=umap.end())
        {
            node* resnode =  umap[key];
            int ans = resnode->val;
            umap.erase(key);
            deletenode(resnode);
            addnode(resnode);
            umap[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(umap.find(key)!=umap.end())
        {
            node* existingnode = umap[key];
            umap.erase(key);
            deletenode(existingnode);
        }
        if(umap.size()==cap)
        {
            umap.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        umap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
