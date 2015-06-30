struct Node{
    int key,val;
    Node(int k,int v):key(k),val(v){}
};
class LRUCache{
public:
    int size;
    list<Node> cacheList;
    map<int,list<Node>::iterator > mp;
    list<Node>::iterator it;
    LRUCache(int capacity) {
        size = capacity;    
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        } else {
            it = mp[key];
            cacheList.splice(cacheList.begin() , cacheList , it);
            mp[key] = cacheList.begin();
            return cacheList.begin()->val;
        }
    }
    
    void set(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (cacheList.size() == size) {
                mp.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(Node(key , value));
            mp[key] = cacheList.begin();
        } else {
            it = mp[key];
            cacheList.splice(cacheList.begin() , cacheList , it);
            mp[key] = cacheList.begin();
            cacheList.begin()->val = value;
        }
    }
};
