class lruDllList{
    public:
        int key;
        int val;
        lruDllList* prev;
        lruDllList* next;
        lruDllList(): key(0), val(0), prev(nullptr), next(nullptr) {}
        lruDllList(int k, int x): key(k), val(x), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int cap;
    unordered_map<int , lruDllList*> cache;
    lruDllList* left;
    lruDllList* right;

    void insert(lruDllList* node)
    {
        lruDllList* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
    void remove(lruDllList* node)
    {
        lruDllList* prev = node->prev;
        lruDllList* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new lruDllList(0, 0);
        right = new lruDllList(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            lruDllList* node = cache[key];
            remove(node);
            insert(node);//last recently used so we insert at back again after removing
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end())
        {
            remove(cache[key]);
        }
        lruDllList* newNode = new lruDllList(key, value);
        cache[key] = newNode;
        insert(newNode);

        if(cache.size()>cap)
        {
            lruDllList* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
