#include <iostream>
#include <map>
#include <deque>
#include <climits>
#include <unordered_map>
using namespace std;
/*
Vectors are same as dynamic arrays with the ability to resize itself automatically when an element 
is inserted or deleted, with their storage

One main difference between vectors and deques is that the latter allows efficient 
insertion at the front of the structure as well as the back.
*/

// Implementation of LRU Cache using two data structures:
// 1. Doubly Linked List
// 2. HashMap

class LRUCache
{
public:
    int cacheSize;
    unordered_map<int, int> m;
    deque<int> dq; // store the keys/cache

    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
    void print();
};

LRUCache::LRUCache(int capacity)
{
    m.clear(); //clear() function is used to remove all the elements from the map container and thus leaving it's size 0.
    dq.clear();
    cacheSize = capacity;
}

int LRUCache::get(int key)
{
    // not found
    if (m.find(key) == m.end())
    {
        return -1;
    }
    else
    {
        // found
        deque<int>::iterator it = dq.begin();
        while (*it != key)
        {
            it++;
        }

        // update queue: update it to most recent used value
        dq.erase(it); //Removes from the deque container either a single element

        dq.push_front(key);

       // cout << "vishal"  << m[key] << endl;

        return m[key];
    }
}

void LRUCache::put(int key, int value)
{
    // not present in cache
    if (m.find(key) == m.end())
    {
        // check if cache is full
        if (cacheSize == dq.size())
        {
            int last = dq.back(); //Returns a reference to the last element in the container.
            dq.pop_back(); //Delete last element (public member function ),push_back  -> add element
            m.erase(last); //Removes the element at pos 
        }
    }
    else
    {
        // present in cache, remove it from queue and map
        deque<int>::iterator it = dq.begin();
        while (*it != key)
        {
            it++;
        }

        dq.erase(it);
        m.erase(key);
    }

    // update the cache
    dq.push_front(key);
    m[key] = value;
}

/*Iterating through the entire list and printing the elements*/
void LRUCache::print()
{
    for (auto it = dq.begin(); it != dq.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main()
{

    LRUCache lRUCache(3);

    lRUCache.put(1, 101); // cache is {1=1}
    lRUCache.print();
    lRUCache.put(2, 201); // cache is {1=1, 2=2}
    lRUCache.print();
    lRUCache.get(1); // return 1
    lRUCache.print();
    lRUCache.put(3, 301); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.print();
    lRUCache.get(2); // returns -1 (not found)
    lRUCache.print();
    lRUCache.put(4, 400); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.print();
    lRUCache.get(1); // return -1 (not found)
    lRUCache.print();
    lRUCache.get(3); // return 3
    lRUCache.print();
    lRUCache.get(4); // return 4
    lRUCache.print();
}