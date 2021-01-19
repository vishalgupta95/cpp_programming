// Implementation of LRU Cache using two data structures:
// 1. Doubly Linked List
// 2. HashMap

class LRUCache {
public:
    int cacheSize;
    map<int, int> m;
    deque<int> dq;
    
    LRUCache(int capacity) {
        m.clear();
        dq.clear();
        cacheSize = capacity;
    }
    
    int get(int key) {
        // not found
        if (m.find(key) == m.end()) {
            return -1;
        } else {
            // found
            deque<int>::iterator it = dq.begin();
            while (*it != key) {
                it++;
            }
            
            // update queue: update it to most recent used value
            dq.erase(it);
            dq.push_front(key);
            
            return m[key];
        }
    }
    
    void put(int key, int value) {
        // not present in cache
        if (m.find(key) == m.end()) {
            // check if cache is full
            if (cacheSize == dq.size()) {
                int last = dq.back();
                dq.pop_back();
                m.erase(last);
            }
        } else {
            // present in cache, remove it from queue and map
            deque<int>::iterator it = dq.begin();
            while (*it != key) {
                it++;
            }
            
            dq.erase(it);
            m.erase(key);
        }
        
        // update the cache
        dq.push_front(key);
        m[key] = value;
    }
};

// Driver Code
int main()
{
    LRUCache ca(4);
 
    ca.put(1);
    
    ca.display();
 
    return 0;
}