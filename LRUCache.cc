    /*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
	*/
class LRUCache{
    
	private: 
	    int capacity;
	    int size;
	    struct Node { // doubly linked list
	        Node *prev, *next;
	        int key;
	        int val;
	        Node(int k, int v) : key(k), val(v) { prev = NULL; next = NULL;}
	    };
	    
	    Node * insert(int k, int v) {
	        //insert a value in the front of the list
	        Node *n = new Node(k, v);
	        if(head == NULL) {
	            head = n;
	            tail = n;
	        } else {
	            n->next =head;
	            head->prev = n;
	            head = n;
	        }
	        return n;
	    }
	    
	    void removeTail() {
	        if(head == tail) {
	            delete tail;
	            head = NULL;
	            tail = NULL;
	        } else {
	            tail = tail->prev;
	            delete tail->next;
	            tail->next = NULL;
	        }
	    }
	    
	    void updateNode(Node *node) {
	        // move n to the front of the list
	        if(node == head) 
	            return;
	        else {
	            node->prev->next = node->next;
	            if(node != tail) 
	                node->next->prev = node->prev;
	            else 
	                tail = node->prev;
	            node->next = head;
	            head->prev = node;
	            head = node;
	        }
	    }
	    
	    Node *head, *tail;
	    
	    unordered_map<int, Node *> map; // map the key to the node
	public:
	    LRUCache(int capacity) {
        	this->capacity = capacity;
			size = 0;
			head = NULL;
			tail = NULL;
	    }
    
	    int get(int key) {
            unordered_map<int, Node *>::iterator mit = map.find(key);
            if(mit == map.end())
                return -1;
            updateNode(mit->second);
            return mit->second->val;
	    }
    
	    void set(int key, int value) {
	        unordered_map<int, Node *>::iterator mit = map.find(key);
            if(mit != map.end()) {
                mit->second->val = value;
                updateNode(mit->second);
            } else {
                if(size == capacity) {
                    // full, invalidate tail
                    map.erase(tail->key);
                    removeTail();
                    size--;
                } 
                Node *n = insert(key, value);
                map[key] = n;
                size++;
            }
	    }
};