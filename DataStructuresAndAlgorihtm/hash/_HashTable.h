/*
 * Created by weyiua on 2021/9/5.
 * hash
 * 使用分离链接法解决hash冲突
 */

#ifndef _HASHTABLE
#define _HASHTABLE

#include <vector>
#include <forward_list>

const int _HASHTABLELEN = 1007;

class Hashtable {
public:
    Hashtable() {
        _hashTable = std::vector<std::forward_list<int> > (_HASHTABLELEN);
    }

    bool insertHashTable(int value) {
        int postion = hashFunction(value);
        _hashTable[postion].push_front(value);
        return true;
    }

    bool deleteHashTable(int value) {
        if(findHashTable(value) == static_cast<std::forward_list<int>::iterator>(nullptr) ) return false;
        _hashTable[hashFunction(value)].erase_after(findHashTable(value));
        return true;
    }

    std::forward_list<int>::iterator findHashTable(int value) {
        int postion = hashFunction(value);
        auto& tempList = _hashTable[postion];
        if(tempList.empty()) return static_cast<std::forward_list<int>::iterator>(nullptr);
        std::forward_list<int>::iterator it = tempList.begin();
        while(it != tempList.end() && *it != value) {
            ++it;
        }
        return it;
    }
private:
    std::vector<std::forward_list<int>> _hashTable;

    int hashFunction(int value) {
        return value % _HASHTABLELEN;
    }
};

#endif

