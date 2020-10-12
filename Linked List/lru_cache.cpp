// 146. LRU Cache

class LRUCache {

// linked list that contains values of keys and their pairs
list<pair<int, int>> keys;

// contains keys and their pointer to the linked list
unordered_map<int, list<pair<int, int>>::iterator> key_address;
int cache_size = 0;

public:
    LRUCache(int capacity) {
        cache_size = capacity;
    }

    int get(int key){

        auto find_key = key_address.find(key);

        // if it is not in the cache
        if(find_key == key_address.end())
            return -1;

        // splice is used to move the elements
        // >move to keys.begin, as this is key used most recently
        // >from keys and iterator is find-key, which will now
        // >point to keys.begin
        keys.splice(keys.begin(), keys, find_key->second);

        // return the value of the key in the linked list.
        return find_key->second->second;
    }

    void put(int key, int value) {

        // if key found
        if(key_address.find(key) != key_address.end())
        {
           // change the value of last
            keys.splice(keys.begin(), keys, key_address[key]);
            key_address[key]->second = value;
            return;
        }

        if(keys.size() >= cache_size)
        {
            int to_delete = keys.end()->first;
            key_address.erase(to_delete);
            keys.pop_back();
        }

        keys.push_front({key, value});
        key_address[key] = keys.begin();

        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
