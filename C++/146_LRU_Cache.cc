class LRUCache {
   private:
    int cap;
    int items;
    map<int, list<pair<int, int> >::iterator> imap;
    list<pair<int, int> > ilist;

   public:
    LRUCache(int capacity) {
        cap = capacity;
        items = 0;
    }

    int get(int key) {
        int value = -1;

        if (imap.find(key) != imap.end()) {
            list<pair<int, int> >::iterator it = imap[key];
            value = it->second;

            ilist.push_front(*it);
            imap[key] = ilist.begin();
            ilist.erase(it);
        }

        return value;
    }

    void put(int key, int value) {
        list<pair<int, int> >::iterator it;

        if (imap.find(key) != imap.end()) {
            it = imap[key];
            it->second = value;
            ilist.push_front(*it);
            imap[key] = ilist.begin();
            ilist.erase(it);
        } else {
            ilist.push_front(pair<int, int>(key, value));
            imap[key] = ilist.begin();

            if (items == cap) {
                pair<int, int> p = ilist.back();
                ilist.pop_back();
                imap.erase(p.first);
            } else {
                items++;
            }
        }
    }
};

/**
 *  * Your LRUCache object will be instantiated and called as such:
 *   * LRUCache obj = new LRUCache(capacity);
 *    * int param_1 = obj.get(key);
 *     * obj.put(key,value);
 *      */
