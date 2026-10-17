class LRUCache {
    int cap;
    std::list<std::pair<int, int>> dll;
    unordered_map<int, std::list<std::pair<int, int>>::iterator> pos;
public:
    LRUCache(int capacity) : cap(capacity) {
        pos.reserve(capacity);
    }
    
    int get(int key) {
        auto it = pos.find(key);
        if(it == pos.end()) return -1;
        dll.splice(dll.begin(), dll, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = pos.find(key);
        if(it != pos.end()){
            it->second->second = value;
            //maintaining lru
            dll.splice(dll.begin(), dll, it->second);
            return;
        }
        if(dll.size() == cap)
        {
            pos.erase(dll.back().first);
            dll.pop_back();
        }
        dll.emplace_front(key, value);
        pos[key] = dll.begin();
    }
};
