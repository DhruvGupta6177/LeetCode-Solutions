class LFUCache {
public:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyValFreq; 
    unordered_map<int, list<int>> freqList;        
    unordered_map<int, list<int>::iterator> keyIter; 

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    void updateFrequency(int key) {
        int freq = keyValFreq[key].second;
        freqList[freq].erase(keyIter[key]);

        
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        
        keyValFreq[key].second++;
        int newFreq = freq + 1;
        freqList[newFreq].push_front(key);
        keyIter[key] = freqList[newFreq].begin();
    }

    int get(int key) {
        if (keyValFreq.find(key) == keyValFreq.end())
            return -1;

        updateFrequency(key);
        return keyValFreq[key].first;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        
        if (keyValFreq.find(key) != keyValFreq.end()) {
            keyValFreq[key].first = value;
            updateFrequency(key);
            return;
        }

        
        if (keyValFreq.size() >= capacity) {
            int evictKey = freqList[minFreq].back(); 
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty())
                freqList.erase(minFreq);
            keyValFreq.erase(evictKey);
            keyIter.erase(evictKey);
        }

        
        keyValFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};
